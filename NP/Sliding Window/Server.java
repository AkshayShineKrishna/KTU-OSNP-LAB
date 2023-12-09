import java.io.*;
import java.net.*;

class Server {
    public static void main(String args[]) {
        String s[] = new String[8];
        int sws = 4, ptr = 0;
        try {
            ServerSocket s1 = new ServerSocket(8000);
            Socket c = s1.accept();
            while (true) {
                BufferedReader b = new BufferedReader(new InputStreamReader(c.getInputStream()));
                String str = b.readLine();
                System.out.println("The no. of frames to be received:" + str);
                int n = Integer.parseInt(str);
                BufferedReader b1 = new BufferedReader(new InputStreamReader(c.getInputStream()));
                if (n <= sws) {
                    for (int i = 0; i < n; i++) {
                        s[ptr] = b1.readLine();
                        System.out.println("From sender frame" + ptr + ": " + s[ptr]);
                        ptr = (++ptr) % 4;
                    }
                    sws = sws - n;
                    PrintWriter p = new PrintWriter(c.getOutputStream(), true);
                    p.println("frame" + ptr + " acknowlegement sent");
                    sws = sws + n;
                } else
                    System.out.println("exceeds window size");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}