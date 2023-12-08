import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.net.*;

public class Client implements ActionListener {

        private JTextArea tArea;
        private JTextField tField;
        private JLabel status;
        private Socket socket;
        private PrintWriter out;
        private BufferedReader in;

        public void createGUI() {
                JFrame frame = new JFrame("Chat - Client");
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setSize(400, 400);
                
                JPanel panel_south = new JPanel();
                JLabel label = new JLabel("Message");
                tField = new JTextField(10);
                JButton btnSend = new JButton("Send");
                btnSend.addActionListener(this);
                panel_south.add(label);
                panel_south.add(tField);
                panel_south.add(btnSend);

                JPanel panel_status = new JPanel();
                status = new JLabel("Waiting for server");
                panel_status.add(new JLabel("Status: "));
                panel_status.add(status);

                tArea = new JTextArea();
                tArea.setEditable(false);

                frame.getContentPane().add(BorderLayout.SOUTH, panel_south);                
		frame.getContentPane().add(BorderLayout.NORTH, panel_status);
                frame.getContentPane().add(BorderLayout.CENTER, tArea);

                frame.setVisible(true);
                tField.requestFocus();		
        }

        public void actionPerformed(ActionEvent event) {
                if(out!=null) {
                        out.println(tField.getText());
                        tArea.append("Me: "+tField.getText()+"\n");
                        tField.setText(null);
                        tField.requestFocus();
                } else {
                        tArea.setText("Wait for server to Connect!");
                }
        }

        public static void main(String args[]) {
                try {
                Client client = new Client();
                client.createGUI();
                client.connectToServer();
                } catch (Exception e) {
                }
        }

        public void connectToServer() throws Exception {
                while(true) {
                try {
                        socket = new Socket(InetAddress.getLocalHost(), 8000);
                        out = new PrintWriter(socket.getOutputStream(), true);
                        in = new BufferedReader(
                                new InputStreamReader(socket.getInputStream()));
                        status.setText("Server Connected");
                        break;
                }catch (Exception exc) {
                        System.out.println("No Server!");                      
                }
                }
                while(true) {
                        String str = in.readLine();
                        tArea.append("Client "+str+"\n");
                }
        }

}