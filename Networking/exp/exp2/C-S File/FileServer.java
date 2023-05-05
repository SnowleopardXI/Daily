import java.io.*;
import java.net.*;

public class FileServer {
    private static final int PORT = 9091; // 服务器监听的端口号

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(PORT); // 创建服务器端Socket对象
            System.out.println("服务器已启动，等待客户端连接...");
            Socket clientSocket = serverSocket.accept(); // 等待客户端连接
            System.out.println("客户端已连接：" + clientSocket.getInetAddress());

            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); // 读取客户端请求
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true); // 向客户端发送响应

            while (true) {
                String request = in.readLine(); // 读取客户端请求

                if (request == null) {
                    break;
                }

                if (request.startsWith("upload ")) { // 处理上传请求
                    String fileName = request.substring(7);
                    receiveFile(fileName, clientSocket);
                } else if (request.startsWith("download ")) { // 处理下载请求
                    String fileName = request.substring(9);
                    sendFile(fileName, clientSocket);
                } else if (request.equals("list")) { // 处理列出目录下文件请求
                    listFiles(clientSocket);
                } else {
                    out.println("Invalid request.");
                }
            }

            clientSocket.close(); // 关闭客户端Socket
            serverSocket.close(); // 关闭服务器Socket
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void receiveFile(String fileName, Socket clientSocket) throws IOException {
        File file = new File(fileName);
        OutputStream out = new FileOutputStream(file); // 创建输出流，将数据写入到指定的文件中
        InputStream in = clientSocket.getInputStream(); // 获取客户端输入流

        byte[] buffer = new byte[1024];
        int bytesRead;

        while ((bytesRead = in.read(buffer)) != -1) { // 不断读取客户端发送的数据，直到读取到结束标记
            out.write(buffer, 0, bytesRead); // 将数据写入文件
        }

        out.close();
        System.out.println("文件已上传：" + fileName);
    }

    private static void sendFile(String fileName, Socket clientSocket) throws IOException {
        File file = new File(fileName);

        if (!file.exists()) { // 如果文件不存在，向客户端发送文件不存在的响应
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            out.println("File not found.");
            return;
        }

        InputStream in = new FileInputStream(file); // 创建输入流，读取文件数据
        OutputStream out = clientSocket.getOutputStream(); // 获取客户端输出流

        byte[] buffer = new byte[1024];
        int bytesRead;

        while ((bytesRead = in.read(buffer)) != -1) { // 不断读取文件数据，直到读取到文件末尾
            out.write(buffer, 0, bytesRead); // 将数据写入客户端输出流
        }

        in.close();
        System.out.println("文件已下载：" + fileName);
    }

    private static void listFiles(Socket clientSocket) throws IOException {
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        File dir = new File("."); // 获取当前目录

        File[] files = dir.listFiles(); // 获取当前目录下的文件列表

        if (files == null) {
            return;
        }

        for (File file : files) {
            if (file.isFile()) {
                out.println(file.getName()); // 将文件名发送给客户端
            }
        }

        out.println("."); // 发送结束标记，告诉客户端文件列表已经发送完毕
        System.out.println("已列出目录下的文件");
    }
}
