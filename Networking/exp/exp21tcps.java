
import java.io.*;
import java.net.*;

public class exp21tcps {
    public static void main(String argv[]) throws Exception {
        String ClientSentence;// 声明字符串变量用于存储字符串输入和传送
        String capitalizedSentence;// 从客户端得到的输入内容
        ServerSocket welcomeSocket = new ServerSocket(9091);// 创建welcomeSocket对象，并在6789端口监听
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();// 获取从客户传来的字符
            BufferedReader infromClient = new BufferedReader(new InputStreamReader(
                    connectionSocket.getInputStream()));// 创建缓冲输入流对象
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());// 创建缓冲输出流对象
            ClientSentence = infromClient.readLine();// 按行读取用户输入等待信息
            capitalizedSentence = ClientSentence.toUpperCase() + "\n";// 将用户输入的字母进行转化
            outToClient.writeBytes(capitalizedSentence);
        }
    }

}
