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
                    p.println(input);
                    System.exit(0);
                }
                int first = 0;
                int second = 1;
                int third = 0;
                int num = Integer.parseInt(input);
                System.out.println("\nFibonacii Series : \n");
                System.out.print(first + ", " + second); 
                for(int i = 0 ; i < num - 2 ; i++){
                    third = first + second;
                    System.out.print(", " + third);
                    first = second;
                    second = third;
                }
                p.println("Fibonacii Series processed successfully");
                
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
