import java.io.*;
import java.net.*;

class Client {
    public static void main(String args[]) {
        String s[] = new String[8];
        int sws = 4, ptr = 0;
        try {
            Socket c = new Socket("localhost", 8000);
            String c1;
            do {
                BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
                System.out.println("The no. of frames to be send:");
                String str = b.readLine();
                PrintWriter p = new PrintWriter(c.getOutputStream(), true);
                p.println(str);
                int n = Integer.parseInt(str);
                BufferedReader b1 = new BufferedReader(new InputStreamReader(c.getInputStream()));
                if (n <= sws) {
                    for (int i = 0; i < n; i++) {
                        System.out.println("Enter the frame data:");
                        s[ptr] = b.readLine();
                        PrintWriter p1 = new PrintWriter(c.getOutputStream(), true);
                        p1.println(s[ptr]);
                        ptr = (++ptr) % 4;
                    }
                    sws = sws - n;
                    String a = b1.readLine();
                    System.out.println("Acknowlegement from " + a);
                    sws = sws + n;
                } else
                    System.out.println("exceeds window size");
                System.out.println("do you want to continue: (y/n) ");
                c1 = b.readLine();
            } while (c1.equals("y"));
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
