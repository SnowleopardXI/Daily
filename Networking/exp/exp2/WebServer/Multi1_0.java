import java.net.*;
import java.io.*;

public class Multi1_0 {
    public static void main(String[] args) throws IOException {
        int port = 8080; // 端口号
        ServerSocket serverSocket = new ServerSocket(port);

        System.out.println("Web Server started on port " + port);

        while (true) {
            Socket clientSocket = serverSocket.accept(); // 监听客户端连接
            new Thread(() -> {
                try {
                    BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); // 读取客户端请求
                    OutputStream out = clientSocket.getOutputStream(); // 响应客户端请求

                    String request = in.readLine(); // 读取请求行
                    System.out.println("Request: " + request);

                    // 响应客户端请求
                    String response = "HTTP/1.0 200 OK\r\n" +
                            "Content-Type: text/html\r\n" +
                            "\r\n" +
                            "<html><body><h1>Hello, World!</h1></body></html>";
                    out.write(response.getBytes("UTF-8"));

                    in.close();
                    out.close();
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();
        }
    }
}
