import java.io.*;
import java.net.*;
import java.util.*;
import java.nio.file.*;

public class Server {
    public static void main(String[] args) {
        Socket c;
        BufferedReader b1;
        PrintWriter p;
        try {
            ServerSocket s = new ServerSocket(8000);
            c = s.accept();
            b1 = new BufferedReader(new InputStreamReader(c.getInputStream()));
            p = new PrintWriter(c.getOutputStream(), true);
            while (true) {
                String fileName = b1.readLine();
                if (fileName.compareToIgnoreCase("exit") == 0) {
                    System.out.println("\nServer Stopped");
                    p.println(fileName);
                    System.exit(0);
                }
                // Read all lines from the file and add them to a list
                try {
                    List<String> lines = Files.readAllLines(Paths.get(fileName));
                    // send no of lines to client
                    p.println(lines.size());
                    // Send each line to client
                    for (String line : lines) {
                        p.println(line);
                    }
                    // clear the list after sending all lines
                    lines.clear();
                    System.out.println("Sent " + fileName + " successfully");
                } catch (Exception e) {
                    System.out.println("File : " + fileName + "not found in server");
                    p.println("1");
                    p.println(fileName + "not found");
                }

            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
