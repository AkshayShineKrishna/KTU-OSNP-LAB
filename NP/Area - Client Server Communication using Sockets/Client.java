import java.io.*;
import java.net.*;

class Client {

    public static void main(String arg[]) {
        BufferedReader b, b1;
        String s1;
        PrintWriter p;
        try {
            Socket s = new Socket("localhost", 8000);
            while (true) {
                b = new BufferedReader(new InputStreamReader(System.in));
                b1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
                p = new PrintWriter(s.getOutputStream(), true);
                System.out.println("Enter radius:");
                s1 = b.readLine();
                p.println(s1);
                String s2 = b1.readLine();
                if (s2.compareTo("exit") == 0) {
                    System.exit(0);
                }
                System.out.println("Area of circle from server : " + s2);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
