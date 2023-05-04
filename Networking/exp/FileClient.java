import java.io.*;
import java.net.*;

public class FileClient {

    public static void main(String[] args) throws IOException {
        int port;
        String IP;
        System.out.println("请输入服务器的IP地址");
        BufferedReader inFromUser1 = new BufferedReader(
                new InputStreamReader(System.in));// 将流连接到标准输入 inFromUser程序的输入流
        IP = inFromUser1.readLine();
        System.out.println("请输入服务器的端口号");
        BufferedReader inFromUser2 = new BufferedReader(
                new InputStreamReader(System.in));// 将流连接到标准输入 inFromUser程序的输入流
        port = Integer.parseInt(inFromUser2.readLine());
        Socket socket = new Socket(IP, port);

        //upload download
        System.out.println("请输入指令和文件名，用空格隔开");
        BufferedReader inFromUser3 = new BufferedReader(
                new InputStreamReader(System.in));// 将流连接到标准输入 inFromUser程序的输入流
        String command = inFromUser3.readLine();
        String[] commandArray = command.split(" ");
        String command1 = commandArray[0];
        String fileName = commandArray[1];
        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
        writer.println(command1);
        writer.println(fileName);

    }
}
