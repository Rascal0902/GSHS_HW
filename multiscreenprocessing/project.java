package Screen;


import java.awt.Frame;
import processing.awt.PSurfaceAWT;
import processing.core.PApplet;
public class project extends PApplet {
    secondApplet second = new secondApplet();
    boolean opened=true; boolean closed=false;
    public static void main(String args[]) {
        PApplet.main("Screen.project");
    }
    public void settings() { size(500,500);}
    public void setup() { background(127);}
    public void draw() {
        if(key==' ' && opened){open(); opened=!opened;closed=!closed;}
        if(key=='r' && closed){close(); opened=!opened;closed=!closed;}
    }
    void open(){
        second = new secondApplet();
        runSketch(new String[]{"sec"},second);
        second.getSurface().setVisible(true);
        second.loop();
    }
    void close(){
        second.dispose();
    }
}
class secondApplet extends PApplet{
    public void settings(){size(500,500);}
    public void setup(){background(0);}
    public void draw(){}
    public void dispose(){
        Frame frame = ( (PSurfaceAWT.SmoothCanvas) ((PSurfaceAWT)surface).getNative()).getFrame();
        frame.dispose();
    }
}
