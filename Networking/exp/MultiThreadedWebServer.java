import java.io.*;
import java.net.*;

public class MultiThreadedWebServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8089); // 监听8089端口
        System.out.println("Web server listening on port 8089...");

        while (true) { // 循环等待客户端连接
            Socket clientSocket = serverSocket.accept(); // 接受客户端连接
            System.out.println("Client connected: " + clientSocket.getInetAddress());

            // 创建新线程处理客户端请求
            Thread clientThread = new Thread(() -> {
                try {
                    // 读取客户端请求
                    BufferedReader inputReader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                    String request = inputReader.readLine();
                    System.out.println("Request: " + request);

                    // 发送响应
                    BufferedWriter outputWriter = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
                    outputWriter.write("HTTP/1.1 200 OK\r\n");
                    outputWriter.write("Content-Type: text/html\r\n");
                    outputWriter.write("\r\n");
                    outputWriter.write("<html><body><h1>Hello, world!</h1></body></html>\r\n");
                    outputWriter.flush();

                    // 关闭连接
                    inputReader.close();
                    outputWriter.close();
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
            clientThread.start();
        }
    }
}
