/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;

import javax.microedition.lcdui.*;
import javax.microedition.midlet.*;

/**
 * @author rhnvrm
 */


public class Midlet extends MIDlet
{
    private Display display; // The display
    private myCanvas canvas; // Canvas
    public Midlet()
    {
        display = Display.getDisplay(this);
        canvas = new myCanvas(this);
    }
    protected void startApp()
    {
        display.setCurrent(canvas);
    }
    protected void pauseApp()
    { }
    protected void destroyApp( boolean unconditional )
    { }
    public void exitMIDlet()
    {
        destroyApp(true);
        notifyDestroyed();
    }
}