/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;

import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

/**
 * @author rhnvrm
 */
public class Midlet extends MIDlet implements CommandListener{

    private Form f;
    private Form f2;
    private Display display;
    private Command exit;
    private ChoiceGroup cg;
    private Form prevForm;
    private Command back;
    
    public void startApp() {
    
        display = Display.getDisplay(this);
        
        cg = new ChoiceGroup("Select Item", Choice.EXCLUSIVE, new String[]{"TextField", "Date", "Ticker"}, null);
        f = new Form("Midlet", new Item[]{cg});
        prevForm = f;
        exit = new Command("Exit", Command.EXIT, 0);
        back = new Command("Back",Command.BACK, 0);
        f.addCommand(exit);
        f.addCommand(new Command("Choose", Command.ITEM, 0));
        f.setCommandListener(this);
        display.setCurrent(f);
    }
    
    public void pauseApp() {
        notifyPaused();
    }
    
    public void destroyApp(boolean unconditional) {
        notifyDestroyed();
    }

    public void commandAction(Command c, Displayable d) {
        if(c == exit){
            notifyDestroyed();
        }
        if(c == back){
            display.setCurrent(prevForm);
        }
        if(c.getLabel().compareTo("Choose") == 0){
            prevForm = f;
            if (cg.getString(cg.getSelectedIndex()).compareTo("TextField") == 0){
                f2 = new Form("Text Field Demo", new Item[]{
                    new TextField("Enter Your Name", null, 30, TextField.ANY)
                });      
            }
            else if (cg.getString(cg.getSelectedIndex()).compareTo("Date") == 0){            
                f2 = new Form("Date Field Demo", new Item[]{
                    new DateField("Date", DateField.DATE)
                });      
            }
            if (cg.getString(cg.getSelectedIndex()).compareTo("Ticker") == 0){
                f2 = new Form("Ticker Field Demo", new Item[]{
                    new TextField("Enter Your Name", null, 30, TextField.ANY)
                });      
            }
            f2.addCommand(back);
            f2.addCommand(new Command("Submit", Command.ITEM, 0));
            f2.setCommandListener(this);
            display.setCurrent(f2);
        }
        if(c.getLabel().compareTo("Submit") == 0){
            if(f2.getTitle().equals("Ticker Field Demo")){
                String label = ((TextField)f2.get(0)).getString();
                f2.setTitle("");
                f2.deleteAll();
                f2.setTicker(new Ticker(label));
            }
            else if(f2.getTitle().equals("Text Field Demo")){
                String label = ((TextField)f2.get(0)).getString();
                f2.append(label);
            }
        }
    }
}
