/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package hello;

import java.io.IOException;
import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;

/**
 * @author rhnvrm
 */
public class Midlet extends MIDlet implements CommandListener {

    private Form f, df, imf;
    private Display display;
    private ChoiceGroup cgprefs;
    private ImageItem i;
    private Command exit;
    private Command show;
    private Command back1;
    private Command back2;
    private Command show_img;
    private Image fruit;
    private String selected_fruit;
    private Displayable d;
    
    public void startApp() {
        f = new Form("Fruits");
        display = Display.getDisplay(this);
        
        d = new Canvas() {
            protected void paint(Graphics g) {
                throw new UnsupportedOperationException("Not supported yet.");
            }
        };
        
        exit = new Command("Exit", Command.EXIT, 0);
        show = new Command("Show", Command.OK, 0);
        f.addCommand(exit);
        f.addCommand(show);
        
        
        cgprefs = new ChoiceGroup("Choose your fruit:", Choice.EXCLUSIVE);
        cgprefs.append("Kiwi", null);
        cgprefs.append("Mango", null);
        cgprefs.append("Apple", null);
        cgprefs.append("Banana", null);
        cgprefs.append("Cherry", null);
        
        
        f.append(cgprefs);
        f.setCommandListener(this);
        display.setCurrent(f);
    }
  
    public void commandAction(Command c, Displayable d){
        if (c == exit){
            destroyApp(true);
        }
        if (c == show){
            int index = cgprefs.getSelectedIndex();
            selected_fruit = cgprefs.getString(index);
            
            df = new Form("Selected Fruit");
            df.append(selected_fruit);
            show_img = new Command("Image", Command.OK, 0);
            back1 = new Command("Back", Command.ITEM, 0);
            df.addCommand(show_img);
            df.addCommand(back1);
            df.setCommandListener(this);

            display.setCurrent(df);
        }
        if (c == show_img){
            imf = new Form("Image");
            try {
                fruit = Image.createImage(selected_fruit+".png");
                imf.append(new ImageItem(null, resizeImage(fruit), ImageItem.LAYOUT_DEFAULT, null));
            } catch (IOException ex) {

            }
            back2 = new Command("Back", Command.ITEM, 0);
            imf.addCommand(back2);
            
            imf.setCommandListener(this);
            display.setCurrent(imf);
        }
        if (c == back1){
            display.setCurrent(f);
        }
        if (c == back2){
            display.setCurrent(df);
        }
    }
    
    public void pauseApp() {
    }
    
    public void destroyApp(boolean unconditional) {
        notifyDestroyed();
    }
    
    /**
     * This methog resizes an image by resampling its pixels
     *
     * @param src The image to be resized
     * @return The resized image
     */
    private Image resizeImage(Image src) {
        int screenWidth = d.getWidth();
        int screenHeight = d.getHeight();
        int srcWidth = src.getWidth();
        int srcHeight = src.getHeight();
        Image tmp = Image.createImage(screenWidth, srcHeight);
        Graphics g = tmp.getGraphics();
        int ratio = (srcWidth << 16) / screenWidth;
        int pos = ratio / 2;

        //Horizontal Resize        

        for (int x = 0; x < screenWidth; x++) {
            g.setClip(x, 0, 1, srcHeight);
            g.drawImage(src, x - (pos >> 16), 0, Graphics.LEFT | Graphics.TOP);
            pos += ratio;
        }

        Image resizedImage = Image.createImage(screenWidth, screenHeight);
        g = resizedImage.getGraphics();
        ratio = (srcHeight << 16) / screenHeight;
        pos = ratio / 2;

        //Vertical resize

        for (int y = 0; y < screenHeight; y++) {
            g.setClip(0, y, screenWidth, 1);
            g.drawImage(tmp, 0, y - (pos >> 16), Graphics.LEFT | Graphics.TOP);
            pos += ratio;
        }
        return resizedImage;

    }//resize image  
    
}
