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
    private Command start;
    private Command exit;
    private Server s;
    
    public class Server implements Runnable {

        private boolean quit = false;
        
        public void run() {
            while (!quit) {
                try {
                    DatagramConnection dgc = (DatagramConnection) Connector.open("datagram://:9001");
                    try {
                        int size = 100;
                        Datagram datagram = dgc.newDatagram(size);
                        dgc.receive(datagram);
                        f.append(
                                new String(datagram.getData()).trim());
                        byte[] payload = "Test Message".getBytes();
                        datagram = dgc.newDatagram(size);
                        datagram =
                                dgc.newDatagram(payload, payload.length);
                        dgc.send(datagram);
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
        f = new Form("Server");
        display=Display.getDisplay(this);
        start = new Command("Clear", Command.OK, 0);
        exit = new Command("Exit", Command.EXIT, 0);
        
        
        
        f.addCommand(exit);
        f.addCommand(start);
        f.setCommandListener(this);
        display.setCurrent(f);
        
        s = new Server();
        Thread serverThread = new Thread(s);
        serverThread.start();
    }
    
    public void pauseApp() {
    }
   
    
    public void commandAction(Command c, Displayable d){
        if(c==start){
            
        }
        if(c == exit){
            s.quit();
            destroyApp(true);
        }
    }
    
    public void destroyApp(boolean unconditional){
        notifyDestroyed();
    }
}