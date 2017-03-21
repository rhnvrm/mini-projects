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
    private int x,y,w,h,speed, dx, dy;
    public myCanvas(Midlet midlet)
    { 
        this.midlet = midlet;
        // Create exit command & listen for events
        cmExit = new Command("Exit", Command.EXIT, 1);
        addCommand(cmExit);
        setCommandListener(this); 
        w = 30;
        h = 30;
        x = getWidth() / 2 - w/2;
        y = getHeight() / 2 - h/2;
        dx = 1;
        dy = 1;
        speed = 5;

    }
    protected void paint(Graphics g) {
        Font font = Font.getFont(Font.FACE_SYSTEM,
        Font.STYLE_PLAIN, Font.SIZE_MEDIUM);
        g.setFont(font);
        g.setColor(255, 255, 255);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(0, 0, 0);
        g.fillRect(x, y, w, h);
        
        
        x += dx * speed;
        y += dy * speed;
        detect_collision();
        try {
            Thread.sleep(100);
        } catch (InterruptedException ex) {
        }
        repaint();
    }
    protected void keyPressed(int keyCode) {
        if (keyCode > 0) {
            if(keyCode == KEY_NUM1){
                dx = -1;
                dy = -1;
            }
            if(keyCode == KEY_NUM2){
                dx = 0;
                dy = -1;
            }
            if(keyCode == KEY_NUM3){
                dx = 1;
                dy = -1;
            }
            if(keyCode == KEY_NUM4){
                dx = -1;
                dy = 0;
            }
            if(keyCode == KEY_NUM5){
                dx = 0;
                dy = 0;
            }
            if(keyCode == KEY_NUM6){
                dx = 1;
                dy = 0;
            }
            if(keyCode == KEY_NUM7){
                dx = -1;
                dy = 1;
            }
            if(keyCode == KEY_NUM8){
                dx = 0;
                dy = 1;
            }
            if(keyCode == KEY_NUM9){
                dx = -1;
                dy = 1;
            }
            repaint();
        } else {
            System.out.println("keyCode " + getGameAction(keyCode));
        }
    }
    public void commandAction(Command c, Displayable d)
    { 
        if (c == cmExit) {
            midlet.exitMIDlet();
        }
    }

    private void detect_collision() {
        if(x < 0) {
            dx = 1;
        }
        else if(x + w > getWidth()) {
            dx -= 1;
        }
        else if(y < 0) {
            dy = 1;
        }
        else if(y + h > getHeight()) {
            dy = -1;
        }
    }
}
