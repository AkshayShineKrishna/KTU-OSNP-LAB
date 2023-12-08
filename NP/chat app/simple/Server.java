import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Runnable {

    private Socket socket[] = new Socket[10];
    private PrintWriter out[] = new PrintWriter[10];
    private BufferedReader in[] = new BufferedReader[10];
    private ServerSocket serverSocket;
    private int clients, temp;

    public static void main(String args[]) {
        Server server = new Server();
        server.acceptClients();
    }

    public void acceptClients() {
        try {
            clients = 0;
            System.out.println("Waiting for clients.");
            serverSocket = new ServerSocket(8000);
            while (true) {
                socket[clients] = serverSocket.accept();
                System.out.println("New Client " + clients);
                out[clients] = new PrintWriter(socket[clients].getOutputStream(), true);
                in[clients] = new BufferedReader(
                        new InputStreamReader(socket[clients].getInputStream()));
                Thread thread = new Thread(this);
                temp = clients;
                thread.start();
                clients++;
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void run() {
        int clientId = temp;
        while (true) {
            try {
                String str = in[clientId].readLine();
                for (int i = 0; i < clients; i++) {
                    if (i != clientId) {
                        out[i].println(clientId + ": " + str);
                    }
                }
            } catch (Exception exc) {
                exc.printStackTrace();
            }
        }
    }
}
