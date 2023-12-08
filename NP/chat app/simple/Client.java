import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class Client {

    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;

    public static void main(String args[]) {
        try {
            Client client = new Client();
            client.connectToServer();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void connectToServer() throws Exception {
        try {
            socket = new Socket(InetAddress.getLocalHost(), 8000);
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println("Server Connected");

            Thread receiveThread = new Thread(() -> {
                while (true) {
                    try {
                        String str = in.readLine();
                        System.out.println("Server: " + str);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
            receiveThread.start();

            BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in));
            while (true) {
                String userInput = consoleInput.readLine();
                out.println(userInput);
            }
        } catch (Exception exc) {
            System.out.println("No Server!");
        }
    }
}

