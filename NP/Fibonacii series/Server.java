import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        Socket c;
        BufferedReader b1;
        PrintWriter p;
        try {
            ServerSocket s = new ServerSocket(8000);
            c = s.accept();
            b1 = new BufferedReader(new InputStreamReader(c.getInputStream()));
            p = new PrintWriter(c.getOutputStream(),true);
            while (true) {
                String input = b1.readLine();
                if (input.compareToIgnoreCase("exit") == 0) {
                    System.out.println("\nServer Stopped");
                    System.exit(0);
                }
                int first = 0;
                int second = 1;
                int third = 0;
                int num = Integer.parseInt(input);
                String first_num = first +", " + second;
                p.println(first_num); 
                for(int i = 0 ; i < num - 2 ; i++){
                    third = first + second;
                    first = second;
                    second = third;
                    p.println(third);
                }
                System.out.println("Fibonacii Series processed successfully");
                
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
