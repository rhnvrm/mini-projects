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
public class Midlet extends MIDlet implements CommandListener{

    //Declare Private Variables
    private Form f, fo;
    private Display display;
    private Command exit, select, back, result;
    private ChoiceGroup cg;
    private TextField x,y,z;
    
    public void startApp() {
        // Initialize Elements for Main Form
        display = Display.getDisplay(this);
        cg = new ChoiceGroup("Select Item", Choice.EXCLUSIVE, new String[]{"Addition", "Subtraction", "Multiplication", "Division"}, null);
        f = new Form("Midlet", new Item[]{cg});
        exit = new Command("Exit", Command.EXIT, 0);
        select = new Command("Select",Command.ITEM, 0);
        f.addCommand(exit);
        f.addCommand(select);
        f.setCommandListener(this);
        display.setCurrent(f);
        
    }
    
    public void pauseApp() {
        notifyPaused();
    }
    
    public void destroyApp(boolean unconditional) {
        notifyDestroyed();
    }
    
    public void commandAction(Command c, Displayable d){
        if(c == exit){
            destroyApp(true);
        }
        if(c == select){
            //Initialize Elements for Operation Form
            x = new TextField("X", null, 30, TextField.ANY);
            y = new TextField("Y", null, 30, TextField.ANY);
            z = new TextField("Result", null, 30, TextField.ANY);
            
            //Create Form Object and Add elelments
            fo = new Form("Operation "+cg.getString(cg.getSelectedIndex()), new Item[]{
                        x,y,z
                    }); 
            back = new Command("Back", Command.BACK, 0);
            result = new Command("Result", Command.OK, 0);
            fo.addCommand(back);
            fo.addCommand(result);
            fo.setCommandListener(this);
            display.setCurrent(fo);
        }
        if(c == back){
            display.setCurrent(f);
        }
        if(c == result){
            //Get Values from Operation Form
            float a = Float.valueOf(x.getString()).floatValue();
            float b = Float.valueOf(y.getString()).floatValue();
            
            //Calculate and Set Result onto Operation Form.
            if(cg.getString(cg.getSelectedIndex()).compareTo("Addition") == 0) {
                z.setString(String.valueOf(a + b));
            }
            else if(cg.getString(cg.getSelectedIndex()).compareTo("Subtraction") == 0) {
                z.setString(String.valueOf(a - b));
            }
            else if(cg.getString(cg.getSelectedIndex()).compareTo("Multiplication") == 0) {
                z.setString(String.valueOf(a * b));
            }
            else if(cg.getString(cg.getSelectedIndex()).compareTo("Division") == 0) {
                z.setString(String.valueOf(a / b));
            }
        }
    } 
}
