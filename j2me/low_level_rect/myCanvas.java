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
    private int x,y,w,h,d;
    public myCanvas(Midlet midlet)
    { 
        this.midlet = midlet;
        // Create exit command & listen for events
        cmExit = new Command("Exit", Command.EXIT, 1);
        addCommand(cmExit);
        setCommandListener(this); 
        w = 50;
        h = 30;
        x = getWidth() / 2;
        y = getHeight() / 2;
        d = 5;
    }
    protected void paint(Graphics g) {
        Font font = Font.getFont(Font.FACE_SYSTEM,
        Font.STYLE_PLAIN, Font.SIZE_MEDIUM);
        g.setFont(font);
        g.setColor(255, 255, 255);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(0, 0, 0);
        g.drawRect(x, y, w, h);
    }
    protected void keyPressed(int keyCode) {
        if (keyCode > 0 && detect_collision(keyCode)) {
            if(keyCode == KEY_NUM2){
                y -= d;
            }
            if(keyCode == KEY_NUM4){
                x -= d;
            }
            if(keyCode == KEY_NUM6){
                x += d;
            }
            if(keyCode == KEY_NUM8){
                y += d;
            }
            repaint();
        } else {
            System.out.println("keyCode " + getGameAction(keyCode));
        }
    }
    public void commandAction(Command c, Displayable d)
    { 
        if (c == cmExit) midlet.exitMIDlet();
    }

    private boolean detect_collision(int keyCode) {
        if (keyCode == KEY_NUM2) {
            if(y - d < 0) {
                y = 0;
                repaint();
                return false;
            }
        }
        if (keyCode == KEY_NUM4) {
            if(x - d < 0) {
                x = 0;
                repaint();
                return false;
            }
        }
        if (keyCode == KEY_NUM6) {
            if(x + w + d > getWidth()) {
                x = getWidth() - w;
                repaint();
                return false;
            }
        }
        if (keyCode == KEY_NUM8) {
            if(y + h + d > getHeight()) {
                y = getHeight() - h;
                repaint();
                return false;
            }
        }
        return true;
    }
}
