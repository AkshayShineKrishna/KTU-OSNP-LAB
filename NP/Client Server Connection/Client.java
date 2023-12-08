import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        BufferedReader b;
        PrintWriter p;
        try{
            Socket s = new Socket("localhost",8000);
            b = new BufferedReader(new InputStreamReader(System.in));
            p = new PrintWriter(s.getOutputStream(),true);
            while (true) {
                System.out.println("Enter message : ");
                String msg = b.readLine();
                p.println(msg);
                if (msg.compareToIgnoreCase("exit") == 0) {
                    System.exit(0);
                }
            }
        }catch(Exception e){
            System.out.println(e);
        }
    }
}
