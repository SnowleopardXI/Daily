import java.io.*;
import java.net.*;

public class exp21udpc {
    public static void main(String args[]) throws Exception {
        String IP;
        int port;
        System.out.println("请输入服务器的IP地址");
        BufferedReader inFromUser1 = new BufferedReader(
                new InputStreamReader(System.in));//将流连接到标准输入 inFromUser程序的输入流
        IP = inFromUser1.readLine();
        System.out.println("请输入服务器的端口号");
        BufferedReader inFromUser2 = new BufferedReader(
                new InputStreamReader(System.in));//将流连接到标准输入 inFromUser程序的输入流
        port = Integer.parseInt(inFromUser2.readLine());
        System.out.println("请输入将要转换的字符串");
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));// 创建缓冲输入流对象
        DatagramSocket clientSocket = new DatagramSocket();// 创建DatagramSocket对象
        InetAddress IPAddress = InetAddress.getByName(IP);// 创建InetAddress对象，封装IP地址
        byte[] sendData = new byte[1024];// 用来存储要发送给服务器的数据
        byte[] receiveData = new byte[1024];// 用来接收从服务器，返回来的数据
        String sentence = inFromUser.readLine();// 从键盘按行读取输入数据
        sendData = sentence.getBytes();// 将输入的数据保存到数组sendData中
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
        // 创建DatagramPacket对象，初始化发送包的基本信息
        clientSocket.send(sendPacket);// 将封装好的数据包对象发送给服务器
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);// 创建接收包对象
        clientSocket.receive(receivePacket);// 从服务端上接收，返回来的数据包
        String modifiedSentence = new String(receivePacket.getData());// 将数据包的比特流转化为String类型
        System.out.println("FROM SERVER:" + modifiedSentence);// 将数据信息进行打印

    }
}
