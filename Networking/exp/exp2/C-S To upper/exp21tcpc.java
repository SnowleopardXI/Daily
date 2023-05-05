import java.io.*;
import java.net.*;

public class exp21tcpc {
    //客户端：

    public static void main(String argv[]) throws Exception
    {
        String IP;
        int port;
        String sentence;//声明字符串变量用于存储字符串输入和传送
        String modifiedSentence;//从服务器得到，并送到用户标准输出
        System.out.println("请输入服务器的IP地址");
        BufferedReader inFromUser1 = new BufferedReader(
                new InputStreamReader(System.in));//将流连接到标准输入 inFromUser程序的输入流
        IP = inFromUser1.readLine();
        System.out.println("请输入服务器的端口号");
        BufferedReader inFromUser2 = new BufferedReader(
                new InputStreamReader(System.in));//将流连接到标准输入 inFromUser程序的输入流
        port = Integer.parseInt(inFromUser2.readLine());
        System.out.println("请输入将要转换的字符串");
        BufferedReader infromUser = new BufferedReader(
                new InputStreamReader(System.in));//将流连接到标准输入 inFromUser程序的输入流
        //用户输入ip地址和端口号
        Socket clientSocket = new Socket(IP, port);//创建套接字，连接到服务器
        DataOutputStream outToServer = new DataOutputStream(
            clientSocket.getOutputStream()); //DataOutputStream包含在java.io.*包中
        BufferedReader infromServer = new BufferedReader(new InputStreamReader(
                        clientSocket.getInputStream()));
        //inFromServer连接套接字的输入流, BufferedReader包含在java.io.*包中
        sentence = infromUser.readLine(); //将用户输入的一行读入到sentence中
        outToServer.writeBytes(sentence + '\n');//outToServer程序的输出流
        modifiedSentence = infromServer.readLine();//当到达服务器时，他们通过服务器端已将该字符串转换完成
        System.out.println("通过服务器端已将该字符串转换完成");
        System.out.println("FROM SERVER:"+
            modifiedSentence);//将服务器返回的内容显示
        clientSocket.close(); //关闭套接字，tcp连接也随之关闭
    }
}
 
 
