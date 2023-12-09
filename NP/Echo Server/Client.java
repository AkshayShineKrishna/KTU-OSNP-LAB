import java.io.*;
import java.net.*;
import java.util.Calendar;

class Client {
    public static void main(String[] args) {
        BufferedReader b1,b2;
        PrintWriter p;
        Calendar cal1,cal2;

        try {
            Socket s = new Socket("localhost",8000);
            b1 = new BufferedReader(new InputStreamReader(System.in));
            b2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
            p = new PrintWriter(s.getOutputStream(),true);
            
            while (true) {
                System.out.println("Enter message :");
                String msg = b1.readLine();
                cal1 = Calendar.getInstance();
                System.out.println(msg + " send at " + cal1.getTime());
                p.println(msg);
                String echoMsg = b2.readLine();
                if (echoMsg.compareToIgnoreCase("exit") == 0) {
                    System.out.println("Client Stopped");
                    System.exit(0);
                }
                System.out.println("Echo : " + echoMsg);
                cal2 = Calendar.getInstance();
                System.out.println(echoMsg + " received at " + cal2.getTime());
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
