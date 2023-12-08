import java.io.*;
import java.net.*;

class Server {

    public static void main(String arg[]) {
        BufferedReader b;
        String s1;
        PrintWriter p;
        try {
            Socket c;
            ServerSocket s = new ServerSocket(8000);
            c = s.accept();
            while (true) {
                b = new BufferedReader(new InputStreamReader(c.getInputStream()));
                p = new PrintWriter(c.getOutputStream(), true);
                s1 = b.readLine();
                if (s1.compareTo("exit") == 0) {
                    p.println("exit");
                    System.out.println("Server Stopped");
                    System.exit(0);
                }
                double d = Double.parseDouble(s1);
                double a = 3.14 * d * d;
                p.println(a);
                System.out.println("Area sent to client");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}