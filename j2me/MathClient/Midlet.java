/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;

import java.io.IOException;
import javax.microedition.io.*;
import javax.microedition.lcdui.*;
import javax.microedition.midlet.*;

/**
 * @author rhnvrm
 */
public class Midlet extends MIDlet implements CommandListener{
    
    private Form f;

    private Display display;
    private Command send;
    private Command exit;
    private Client client;
    
    public class Client implements Runnable {

        private boolean quit = false;

        public void run() {
            while (!quit) {
                try {
                    DatagramConnection dgc = (DatagramConnection) Connector.open("datagram://localhost:9001");
                    
                    try {
                        byte[] payload = "Test Message".getBytes();
                        Datagram datagram =
                                dgc.newDatagram(payload, payload.length);
                        dgc.send(datagram);
                        int size = 100;
                        Datagram datagram_r = dgc.newDatagram(size);
                        dgc.receive(datagram_r);
                        f.append(
                                new String(datagram_r.getData()).trim());
                    } finally {
                        dgc.close();
                    }
                } catch (IOException x) {
                    x.printStackTrace();
                }
            }
        }

        public void quit() {
            quit = true;
        }
    }
    
    public void startApp() {
        f = new Form("Client");
        display=Display.getDisplay(this);
        send = new Command("Send", Command.OK, 0);
        exit = new Command("Exit", Command.EXIT, 0);
        f.addCommand(exit);
        f.addCommand(send);
        f.setCommandListener(this);
        display.setCurrent(f);
    }
    
    public void pauseApp() {
    }
   
    
    public void commandAction(Command c, Displayable d){
        if(c==send){
            client = new Client();
            Thread serverThread = new Thread(client);
            serverThread.start();
        }
        if(c == exit){
            client.quit();
            destroyApp(true);
        }
    }
    
    public void destroyApp(boolean unconditional){
        notifyDestroyed();
    }
}