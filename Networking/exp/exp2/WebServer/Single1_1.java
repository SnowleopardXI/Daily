import java.net.*;
import java.io.*;

public class Single1_1 {
    public static void main(String[] args) throws IOException {
        int port = 8080; // 端口号
        ServerSocket serverSocket = new ServerSocket(port);

        System.out.println("Web Server started on port " + port);

        while (true) {
            Socket clientSocket = serverSocket.accept(); // 监听客户端连接
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); // 读取客户端请求
            OutputStream out = clientSocket.getOutputStream(); // 响应客户端请求

            String request = in.readLine(); // 读取请求行
            System.out.println("Request: " + request);

            // 响应客户端请求
            String response = "HTTP/1.1 200 OK\r\n" +
                    "Content-Type: text/html\r\n" +
                    "Connection: keep-alive\r\n" +
                    "\r\n" +
                    "<html><body><h1>Hello, World!</h1></body></html>";
            out.write(response.getBytes("UTF-8"));
            // 继续读取并响应客户端请求，直到明确指出连接结束为止
            while (true) {
                String line = in.readLine();
                if (line == null || line.isEmpty()) {
                    break;
                }
                System.out.println(line);
            }

            in.close();
            out.close();
            clientSocket.close();
        }
    }
}