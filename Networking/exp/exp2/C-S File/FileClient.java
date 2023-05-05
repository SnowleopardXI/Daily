import java.io.*;
import java.net.*;

public class FileClient {

    public static void main(String[] args) {
        try {
            int SERVER_PORT;
            String SERVER_HOST;
            System.out.print("请输入服务器地址：");
            BufferedReader in1 = new BufferedReader(new InputStreamReader(System.in));
            SERVER_HOST = in1.readLine();
            System.out.print("请输入服务器端口：");
            BufferedReader in2 = new BufferedReader(new InputStreamReader(System.in));
            SERVER_PORT = Integer.parseInt(in2.readLine());
            Socket socket = new Socket(SERVER_HOST, SERVER_PORT); // 创建客户端Socket对象
            System.out.println("连接到服务器：" + socket.getInetAddress());

            BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); // 读取用户输入
            BufferedReader serverIn = new BufferedReader(new InputStreamReader(socket.getInputStream())); // 读取服务器响应
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true); // 向服务器发送请求

            while (true) {
                System.out.print("请输入要执行的操作（upload 文件名、download 文件名、list）：");
                String input = in.readLine(); // 读取用户输入

                if (input == null || input.isEmpty()) {
                    break;
                }

                out.println(input); // 发送请求到服务器

                if (input.startsWith("upload ")) { // 处理上传请求
                    String fileName = input.substring(7);

                    try {
                        sendFile(fileName, socket); // 上传指定的文件
                        System.out.println("文件已上传：" + fileName);
                    } catch (IOException e) {
                        System.out.println("文件上传失败：" + e.getMessage());
                    }
                } else if (input.startsWith("download ")) { // 处理下载请求
                    String fileName = input.substring(9);

                    try {
                        receiveFile(fileName, socket); // 下载指定的文件
                        System.out.println("文件已下载：" + fileName);
                    } catch (IOException e) {
                        System.out.println("文件下载失败：" + e.getMessage());
                    }
                } else if (input.equals("list")) { // 处理列出目录下文件请求
                    System.out.println("目录下的文件列表：");

                    while (true) {
                        String line = serverIn.readLine(); // 读取服务器发送的一行数据

                        if (line.equals(".")) { // 如果收到结束标记，跳出循环
                            break;
                        }

                        System.out.println(line); // 输出文件名
                    }
                } else {
                    System.out.println("无效请求：" + input);
                }
            }

            socket.close(); // 关闭客户端Socket
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sendFile(String fileName, Socket socket) throws IOException {
        File file = new File(fileName);

        if (!file.exists()) { // 如果文件不存在，抛出异常
            throw new FileNotFoundException("File not found: " + fileName);
        }

        InputStream in = new FileInputStream(file); // 创建输入流，读取文件数据
        OutputStream out = socket.getOutputStream(); // 获取服务器输出流

        byte[] buffer = new byte[1024];
        int bytesRead;

        while ((bytesRead = in.read(buffer)) != -1) { // 不断读取文件数据，直到读取到文件末尾
            out.write(buffer, 0, bytesRead); // 将数据写入服务器输出流
        }

        in.close();
    }

    private static void receiveFile(String fileName, Socket socket) throws IOException {
        File file = new File(fileName);

        OutputStream out = new FileOutputStream(file); // 创建输出流，写入文件数据

        InputStream in = socket.getInputStream(); // 获取服务器输入流
    
        byte[] buffer = new byte[1024];
        int bytesRead;
    
        while ((bytesRead = in.read(buffer)) != -1) { // 不断读取服务器发送的数据，直到读取到结束标记
            if (bytesRead == 4 && buffer[0] == '.' && buffer[1] == '\r' && buffer[2] == '\n' && buffer[3] == '\r') {
                break; // 如果读取到结束标记，跳出循环
            }
    
            out.write(buffer, 0, bytesRead); // 将数据写入文件
        }
    
        out.close();
    }
}    