import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        Socket c;
        BufferedReader b;

        try {
            ServerSocket s = new ServerSocket(8000);
            c = s.accept();
            b = new BufferedReader(new InputStreamReader(c.getInputStream()));
            while (true) {
                String msg = b.readLine();
                if (msg.compareToIgnoreCase("exit") == 0) {
                    System.exit(0);
                }
                System.out.println("Client : " + msg);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}
