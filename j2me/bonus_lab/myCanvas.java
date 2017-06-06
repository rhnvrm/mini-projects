/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;
import javax.microedition.lcdui.*;
/**
 *
 * @author rhnvrm
 */
public class myCanvas extends Canvas implements CommandListener {
    private Command cmExit, show; // Exit midlet
    private Midlet midlet;
    private int w,h;
    private boolean show_button;
    
    public myCanvas(Midlet midlet)
    { 
        this.midlet = midlet;
        // Create exit command & listen for events
        cmExit = new Command("Exit", Command.EXIT, 1);
        addCommand(cmExit);
        show = new Command("Show Button", Command.EXIT, 1);
        addCommand(show);
        setCommandListener(this); 
        w = 120;
        h = 40;
        show_button = false;
    }
    protected void paint(Graphics g) {
        Font font = Font.getFont(Font.FACE_SYSTEM,
        Font.STYLE_PLAIN, Font.SIZE_MEDIUM);
        g.setFont(font);
        //bg
        g.setColor(255, 255, 255);
        g.fillRect(0, 0, getWidth(), getHeight());
        if(show_button){
            //base
            g.setColor(0, 138, 64);
            g.fillRect(getWidth()/2 - w/2, getHeight()/2 -h/2, w, h);
            //light base
            g.setColor(0, 237, 111);
            g.fillRect(getWidth()/2 - w/2, getHeight()/2 -h/2, w-5, h-5);
            //main
            g.setColor(0, 204, 95);        
            g.fillRect(getWidth()/2 - w/2 +5, getHeight()/2 -h/2 +5, w-10, h-10);
            //triangles
            g.setColor(0, 237, 111);
            g.fillTriangle(getWidth()/2 + w/2 , getHeight()/2 -h/2 , getWidth()/2 + w/2 -5, getHeight()/2 -h/2, getWidth()/2 + w/2 -5, getHeight()/2 -h/2+5);
            g.fillTriangle(getWidth()/2 - w/2 , getHeight()/2 +h/2 -5, getWidth()/2 - w/2 +5, getHeight()/2 +h/2-5, getWidth()/2 - w/2 , getHeight()/2 +h/2);

            g.setColor(255, 255, 255);
            g.drawString("Rohan Verma",getWidth()/2, getHeight()/2+2, Graphics.VCENTER | Graphics.HCENTER);
        }

    }
    
    public void commandAction(Command c, Displayable d)
    { 
        if (c == cmExit) {
            midlet.exitMIDlet();
        }
        if (c == show) {
            show_button = true;
            repaint();
        }
    }

    
}
