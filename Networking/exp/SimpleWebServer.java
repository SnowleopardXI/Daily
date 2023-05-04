import java.io.*;
import java.net.*;

public class SimpleWebServer {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8089); // 监听8080端口
        System.out.println("Web server listening on port 8089...");

        while (true) { // 循环等待客户端连接
            Socket clientSocket = serverSocket.accept(); // 接受客户端连接
            System.out.println("Client connected: " + clientSocket.getInetAddress());

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
        }
    }
}
