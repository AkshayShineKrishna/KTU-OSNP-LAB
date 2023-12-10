import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        BufferedReader b1,b2;
        PrintWriter p;
        try {
            Socket s = new Socket("localhost",8000);
            b1 = new BufferedReader(new InputStreamReader(System.in));
            b2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
            p = new PrintWriter(s.getOutputStream(),true);
            while (true) {
                System.out.println("Enter file name : ");
                String fileName = b1.readLine();
                p.println(fileName);
                String serverResponse = b2.readLine();
                if (serverResponse.compareToIgnoreCase("exit") == 0) {
                    System.out.println("Client Stopped");
                    System.exit(0);
                }
                int contentLength = Integer.parseInt(serverResponse);
                System.out.println("Content of " + fileName + " : ");
                for(int i=0;i<contentLength;i++){
                    String content = b2.readLine();
                    System.out.println(content);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
