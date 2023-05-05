import java.io.*;
import java.net.*;

public class exp21udps {
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(9091);// 创建serverSocket对象，并在9091端口监听
        byte[] sendData = new byte[1024];// 用来存储要发送给服务器的数据
        byte[] receiveData = new byte[1024];// 用来接收从服务器，返回来的数据
        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);// 创建接收包对象
            serverSocket.receive(receivePacket);// 从客户端上接收，发送来的数据包
            String sentence = new String(receivePacket.getData());// 将数据包的比特流转化为String类型
            InetAddress IPAddress = receivePacket.getAddress();// 获取客户端的ip地址
            int port = receivePacket.getPort();// 获取客户端的端口号
            String capitalizedSentence = sentence.toUpperCase();// 对数据进行大小写转化
            sendData = capitalizedSentence.getBytes();// 将转化之后的数据转化成比特流
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);// 创建DatagramPacket对象，初始化发送包的基本信息
            serverSocket.send(sendPacket);// 将数据发给客户端
        }

    }
}