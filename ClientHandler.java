import java.net.*;
import java.io.*;

// Handles read write for client
public class ClientHandler implements Runnable{

    private Socket clientSocket;
    
    public ClientHandler(Socket clientSocket){
        this.clientSocket = clientSocket;
    }

    public void run(){

        String s;
        BufferedReader in = null;
        PrintWriter out = null;

        try {
            // Streams 
            out = new PrintWriter(clientSocket.getOutputStream(), true);                   
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            
        } catch (IOException e) {
            //System.out.println("Exception caught when trying to listen on port " + portNum + " or listening for a connection");
            System.out.println(e.getMessage());
        }

        // Read / Write
        while(true)
        {
            try {
                s = in.readLine();
                out.println(s);
            } catch (IOException e){
                System.out.println("Read failed");
                System.exit(-1);
            }
        }
    }
}