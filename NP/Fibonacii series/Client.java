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
                System.out.println("Enter a number : ");
                String num = b1.readLine();
                p.println(num);
                String msg = b2.readLine();
                System.out.println("Server : " + msg);
                if (msg.compareToIgnoreCase("exit") == 0) {
                    System.out.println("Client Stopped");
                    System.exit(0);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
