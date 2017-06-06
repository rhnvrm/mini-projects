/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;

import java.io.IOException;
import java.io.InputStream;
import javax.microedition.io.*;
import javax.microedition.lcdui.*;
import javax.microedition.midlet.*;

/**
 * @author rhnvrm
 */
public class Midlet extends MIDlet implements CommandListener{

    private String text;
    private Form f;
    private Display display;
    private Command exit;
    
    
    public void startApp() {
        HttpConnection c = null;
        InputStream s = null;
        String url = "http://www.gzip.org/algorithm.txt";
        try {
            c = (HttpConnection) Connector.open(url);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        try {
            s = c.openInputStream();
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        f = new Form("Networking");
        display = Display.getDisplay(this);
        exit = new Command("Exit", Command.EXIT, 0);
        f.addCommand(exit);
        f.setCommandListener(this);

        byte[] buffer = new byte[1024];
        StringBuffer sb = new StringBuffer();
        int readIn = 0;
        try {
            while ((readIn = s.read(buffer)) > 0) {
                String temp = new String(buffer, 0, readIn);
                sb.append(temp);
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        text = sb.toString();
        
        f.append(text);
        display.setCurrent(f);
    }
    
    public void commandAction(Command c, Displayable d){
        if(c == exit){
            destroyApp(true);
        }
    }
    
    public void pauseApp() {
    }
    
    public void destroyApp(boolean unconditional) {
        notifyDestroyed();
    }
}
