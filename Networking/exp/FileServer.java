import java.io.*;
import java.net.*;

public class FileServer {
    private static final int PORT = 9091;
    private static final String FILE_PATH = "D:\\temp\\";

    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(PORT);
        System.out.println("Server started on port " + PORT);

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Connection from " + clientSocket);

            BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            // 等待客户端upload download指令
            String command = reader.readLine();
            if (command.equals("upload")) {
                String fileName = reader.readLine();
                System.out.println("uploading file " + fileName);
                File file = new File(FILE_PATH + fileName);
                if (file.exists()) {
                    System.out.println("File already exists");
                    PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
                    writer.println("EXISTS");
                } else {
                    PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
                    writer.println("READY");
                    FileOutputStream outputStream = new FileOutputStream(file);
                    InputStream inputStream = clientSocket.getInputStream();

                    byte[] buffer = new byte[4096];
                    int count;
                    while ((count = inputStream.read(buffer)) > 0) {
                        outputStream.write(buffer, 0, count);
                    }

                    inputStream.close();
                    outputStream.close();
                    clientSocket.close();
                    System.out.println("File " + fileName + " received from client.");
                }
            } else if (command.equals("download")) {
                String fileName = reader.readLine();
                File file = new File(FILE_PATH + fileName);
                if (!file.exists()) {
                    System.out.println("File not found");
                    PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
                    writer.println("NOTEXISTS");
                } else {
                    PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
                    writer.println("READY");
                    FileInputStream inputStream = new FileInputStream(file);
                    OutputStream outputStream = clientSocket.getOutputStream();

                    byte[] buffer = new byte[4096];
                    int count;
                    while ((count = inputStream.read(buffer)) > 0) {
                        outputStream.write(buffer, 0, count);
                    }

                    inputStream.close();
                    outputStream.close();
                    clientSocket.close();
                    System.out.println("File " + fileName + " sent to client.");
                }
            }
            
        }
    }
}
