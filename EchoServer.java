/* Assignment 3 - Question 2 - EchoServer.java
   Authors: John Hebb & Matthew Souter
   Date: Monday, November 4th, 2018
   Description: This program takes in 7 values and creates 3 different threads, one to find the average of the numbers, one to find the max value and one to find the min value
   Github Link- https://github.com/John-Hebb/OS_Assignment3/blob/master/EchoServer.java
*/

import java.net.*;
import java.io.*;

public class EchoServer {
    public static void main(String[] args) throws IOException {

        int portNumber = 9999;
        ServerSocket serverSocket = null;

        try {
            serverSocket = new ServerSocket(portNumber);
        } catch (IOException e){
            System.out.println("port error");
            System.out.println(e.getMessage());
        }

        while(true){
            
            ClientHandler clientHandler;

            try{
                clientHandler = new ClientHandler(serverSocket.accept());
                Thread t = new Thread(clientHandler);
                t.start();
            } catch(IOException e){
                System.out.println("Accept failed");
            }
        }
    }
}