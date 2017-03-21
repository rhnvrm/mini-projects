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
    private Command cmExit; // Exit midlet
    private Midlet midlet;
    private String message = "Keyname, Keycode";
    public myCanvas(Midlet midlet)
    { 
        this.midlet = midlet;
        // Create exit command & listen for events
        cmExit = new Command("Exit", Command.EXIT, 1);
        addCommand(cmExit);
        setCommandListener(this); 
    }
    protected void paint(Graphics g) {
        Font font = Font.getFont(Font.FACE_SYSTEM,
        Font.STYLE_PLAIN, Font.SIZE_MEDIUM);
        g.setFont(font);
        g.setColor(255, 255, 255);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(0, 0, 0);
        g.drawString(message,getWidth()/2, getHeight()/2, Graphics.VCENTER | Graphics.HCENTER);
    }
    protected void keyPressed(int keyCode) {
        if (keyCode > 0) {
            message = "" + getKeyName(keyCode) + ", " + keyCode;
            repaint();
        } else {
            System.out.println("keyPressed action " + getGameAction(keyCode));
        }
    }
    public void commandAction(Command c, Displayable d)
    { 
        if (c == cmExit) midlet.exitMIDlet();
    }
} // end class
