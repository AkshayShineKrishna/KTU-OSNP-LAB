import java.io.*;
import java.net.*;

class Server {
    public static void main(String[] args) {
        BufferedReader b;
        PrintWriter p;
        Socket c;
        try {
            ServerSocket s = new ServerSocket(8000);
            c = s.accept();
            b = new BufferedReader(new InputStreamReader(c.getInputStream()));
            p = new PrintWriter(c.getOutputStream(),true);
            while (true) {
                String msg = b.readLine();
                if (msg.compareToIgnoreCase("exit") == 0) {
                    System.out.println("Server Stopped");
                    p.println(msg);
                    System.exit(0);
                }
                System.out.println("String from client : " + msg);
                p.println(msg);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
