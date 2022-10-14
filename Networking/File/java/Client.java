import java.io.*;
import java.net.InetAddress;
import java.net.Socket;

public class Client {
  public static void main(String[] args) throws Exception {
    Socket socket = new Socket(InetAddress.getByName("127.0.0.1"), 9000);
    OutputStream os = socket.getOutputStream();
    FileInputStream fis = new FileInputStream(new File("upload.jpg"));
    byte[] buffer = new byte[1024];
    int len;
    while ((len = fis.read(buffer)) != -1){
      os.write(buffer, 0, len);
    }
    socket.shutdownOutput();
    InputStream inputStream = socket.getInputStream();
    ByteArrayOutputStream baos = new ByteArrayOutputStream();

    byte[] buffer2 = new byte[1024];
    int len2;
    while ((len2 = inputStream.read(buffer2)) != -1){
      baos.write(buffer2, 0, len2);
    }
    System.out.println(baos.toString());

    fis.close();
    os.close();
    socket.close();

  }

}