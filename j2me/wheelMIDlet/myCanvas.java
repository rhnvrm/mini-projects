/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import javax.microedition.lcdui.*;
/**
 *
 * @author rhnvrm
 */
public class myCanvas extends Canvas implements CommandListener {
    private Command cmExit; // Exit midlet
    private wheelMIDlet midlet;
    private int angle;
    private int radius, speed, change;
    private int mid_x, mid_y;
    private int prev_mx, prev_my, mx, my;
    
    public myCanvas(wheelMIDlet midlet)
    { 
        this.midlet = midlet;
        // Create exit command & listen for events
        cmExit = new Command("Exit", Command.EXIT, 1);
        addCommand(cmExit);
        setCommandListener(this); 
        angle = 0;
        radius = 100;
        mid_x = getWidth()/2 - radius/2;
        mid_y = getHeight()/2 - radius/2;
        speed = 0;
        change = 5;
    }
    
    protected void paint(Graphics g) {
        g.setColor(0x000000); // Whatever color you wish to clear with
        g.setClip(0,0,getWidth(),getHeight());
        g.fillRect(0,0,getWidth(),getHeight());
        g.setColor(255, 0, 0);
        g.fillArc(mid_x, mid_y, radius, radius, angle, 120);
        g.setColor(0, 255, 0);
        g.fillArc(mid_x, mid_y, radius, radius, angle - 120, 120);
        g.setColor(0, 0, 255);
        g.fillArc(mid_x, mid_y, radius, radius, angle - 240, 120);
        try {
            Thread.sleep(100);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
        angle -= speed;
        repaint();        
    }
    
    protected void keyPressed(int keyCode) {
        
        if(keyCode == getKeyCode(UP)){
            speed += change;
        }
        if(keyCode == getKeyCode(DOWN)){
            speed = speed-change>=0?speed-change:0;
        }
        repaint();
    }

    protected void pointerReleased(int x, int y) {
       mx = x;
       my = y;
       int dx = prev_mx - mx;
       int scaled_change = Math.abs(dx)*change*2/getWidth();
       System.out.println(scaled_change);
       if(dx < 0){
           speed += scaled_change;
       }
       else if(dx > 0){
           speed = speed-scaled_change>=0?speed-scaled_change:0;
       }
       repaint();
    }
    
    protected void pointerPressed(int x, int y) {
        prev_mx = x;
        prev_my = y;
    }
   
    
    public void commandAction(Command c, Displayable d)
    { 
        if (c == cmExit) {
            midlet.exitMIDlet();
        }
    }
}
