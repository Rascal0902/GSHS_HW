import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
MySystem system;
int kps=0, record=0;
long s, e;
Queue<keyblock> view = new LinkedList<keyblock>();

void setup() {
  size(1250, 500);
  s=System.currentTimeMillis();
  background(255);
  system= new TestSys();
  makekey();
  textAlign(CENTER);
}
void draw() {
  background(255);
  system.display();
  make();
}
public void makekey() {
  view.add(new keyblock('A', 50, 350, 100, 100));
  view.add(new keyblock('S', 200, 350, 100, 100));
  view.add(new keyblock('D', 350, 350, 100, 100));
  view.add(new keyblock('F', 500, 350, 100, 100));
  view.add(new keyblock('J', 650, 350, 100, 100));
  view.add(new keyblock('K', 800, 350, 100, 100));
  view.add(new keyblock('L', 950, 350, 100, 100));
  view.add(new keyblock(';', 1100, 350, 100, 100));
}
public void make() {
  int total=0;
  Iterator it = view.iterator();
  while (it.hasNext()) {
    keyblock tmp = (keyblock)it.next();
    tmp.display();
    total += tmp.total;
  }
  stroke(0);
  fill(0);
  textSize(20);
  text("total : "+total, 50, 20);
  e=System.currentTimeMillis();
  if (e-s>1000) {
    stroke(0);
    fill(0);
    textSize(20);
    text("kps : "+kps, 50, 50);
    record=kps;
    s=e;
    kps=0;
  } else {
    stroke(0);
    fill(0);
    textSize(20);
    text("kps : "+record, 50, 50);
  }
}
class keyblock {
  int total=0;
  char key;
  float x, y, dx, dy, vanish = 0, vanished=0, alpha=5, alp=50, velo=10;
  float clickR=0, clickG=0, clickB=255, noteR=255, noteG=0, noteB=255;
  Queue<PVector> past = new LinkedList<PVector>();
  boolean viewer = true, push = false, click_visible=true, note_visible=true, onetotalloop=true;
  keyblock(char key, float x, float y, float dx, float dy) {
    this.key = key; 
    this.x=x; 
    this.y=y; 
    this.dx=dx; 
    this.dy=dy;
  }
  void click_color(float R, float G, float B) {
    clickR=R;
    clickG=G;
    clickB=B;
  }
  void note_color(float R, float G, float B) {
    noteR=R;
    noteG=G;
    noteB=B;
  }
  void view() {
    viewer = !viewer;
  }
  void display() {
    vanish+=velo;
    if (system.keyboardManager.isPressed(key) && click_visible) {
      if (onetotalloop) {
        total++;
        kps++;
      }
      onetotalloop=false;
      stroke(0);
      strokeWeight(5);
      fill(clickR, clickG, clickB);
      rect(x, y, dx, dy);
      stroke(0);
      fill(0);
      textSize(40);
      text(key, x+dx/2, y+dy/2);
      textSize(20);
      text(total, x+dx/2, y+dy/2+35);
    } else if (!system.keyboardManager.isPressed(key) && click_visible) {
      onetotalloop=true;
      stroke(0);
      strokeWeight(5);
      fill(255);
      rect(x, y, dx, dy);
      stroke(0);
      fill(0);
      textSize(40);
      text(key, x+dx/2, y+dy/2);
      textSize(20);
      text(total, x+dx/2, y+dy/2+35);
    }
    if (system.keyboardManager.isPressed(key) && note_visible) {
      vanished+=velo;
      push=true;
      Iterator I = past.iterator();
      while (I.hasNext()) {
        PVector d = (PVector) I.next();
        float length = d.x;
        float temp = d.y; //vanish
        fill(noteR, noteG, noteB, alp);
        stroke(noteR, noteG, noteB, alp);
        strokeWeight(0);
        rect(this.x, this.y+temp-vanish-length-alpha, this.dx, length);
      }
      while (!past.isEmpty()) {
        PVector no = past.peek();
        if (this.y+no.y-vanish<0) {
          past.remove();
        } else {
          break;
        }
      }
      fill(noteR, noteG, noteB, alp);
      stroke(noteR, noteG, noteB, alp);
      strokeWeight(0);
      rect(this.x, this.y-vanished-alpha, this.dx, vanished);
    } else if (!system.keyboardManager.isPressed(key) && note_visible) {
      if (push) {
        past.add(new PVector(vanished, vanish));
        push = false;
      }
      vanished=0;
      Iterator I = past.iterator();
      while (I.hasNext()) {
        PVector d = (PVector) I.next();
        float length = d.x;
        float temp = d.y; //vanish
        fill(noteR, noteG, noteB, alp);
        stroke(noteR, noteG, noteB, alp);
        strokeWeight(0);
        rect(this.x, this.y+temp-vanish-length-alpha, this.dx, length);
      }
      while (!past.isEmpty()) {
        PVector no = past.peek();
        if (this.y+no.y-vanish<0) {
          past.remove();
        } else {
          break;
        }
      }
    }
  }
}
public void mousePressed() {
  system.mouseManager.onMousePressed(mouseX, mouseY, mouseButton);
}
public void mouseReleased() {
  system.mouseManager.onMouseReleased(mouseX, mouseY, mouseButton);
}
public void mouseMoved() {
  system.mouseManager.onMouseMoved(mouseX, mouseY);
}
public void mouseDragged() {
  system.mouseManager.onMouseMoved(mouseX, mouseY);
}
public void keyPressed() {
  system.keyboardManager.onKeyPress(key, keyCode);
}
public void keyReleased() {
  system.keyboardManager.onKeyRelease(key, keyCode);
}
abstract class MySystem {
  KeyboardManager keyboardManager = new KeyboardManager();
  MouseManager mouseManager = new MouseManager();
  MySystem() {
  }
  abstract public void init();
  abstract public void display();
}
class TestSys extends MySystem {
  char c;
  TestSys() {
    super();
    init();
  }
  public void init() {
    c='f';
  }
  public void display() {
    strokeWeight(2);
    fill(255);
    stroke(0);
    ellipseMode(CENTER);
    if ((new MouseManager()).getButtonPressed(0)) {
      fill(255, 0, 0);
    }
    if ((new MouseManager()).getButtonPressed(1)) {
      fill(0, 255, 0);
    }
    if ((new MouseManager()).getButtonPressed(2)) {
      fill(0, 0, 255);
    }
    ellipse((new MouseManager()).getMouseLocation().x, (new MouseManager()).getMouseLocation().y, 10, 10);
    strokeWeight(5);
  }
}
class KeyboardManager {
  private static final int keyNum = 60;
  private boolean[] keyState = new boolean[keyNum]; //a~z: 0~25, 0~9: 26,35, ' '=36, 'ENTER'= 37, arrow lurd: 38~41, shift,ctrl,alt: 42~44
  KeyboardManager() {
    for (int i=0; i<keyNum; i++) {
      keyState[i] = false;
    }
  }
  public void onKeyPress(char k, int kc) {
    if (calKey(k, kc)==-1)return;
    keyState[calKey(k, kc)] = true;
  }
  public void onKeyRelease(char k, int kc) {
    if (calKey(k, kc)==-1)return;
    keyState[calKey(k, kc)] = false;
  }
  public boolean isPressed(int k) {
    return keyState[calKey((char)CODED, k)];
  }
  public boolean isPressed(char k) {
    return keyState[calKey(k, 0)];
  }
  public boolean isPressed() {
    boolean t = false;
    for (int i=0; i<keyNum; i++) {
      t = t|keyState[i];
    }
    return t;
  }
  private int calKey(char k, int kc) {
    if (k-'a'>=0&&k-'z'<=0) {
      return k-'a';
    } else if (k-'A'>=0&&k-'Z'<=0) {
      return k-'A';
    } else if (k-'0'>=0&&k-'9'<=0) {
      return k-'0'+'z'-'a'+1;
    } else if (k==' ') {
      return  36;
    } else if (k=='\n') {
      return  37;
    } else if (k==CODED) {
      if (kc-LEFT>=0&&38+kc-LEFT<=41) {
        return 38+kc-LEFT;
      } else if (kc-SHIFT>=0&&kc-SHIFT+42<=44) {
        return 42+kc-SHIFT;
      }
    } else if (k==27) {
      return  45;
    }//esc
    else {
      switch(k) {
      case '-':
      case '_':
        return 46;
      case '=':
      case '+':
        return 47;
      case '{':
      case '[':
        return 48;
      case ']':
      case '}':
        return 49;
      case ';':
      case ':':
        return 50;
      case '\'':
      case '"':
        return 51;
      case ',':
      case '<':
        return 52;
      case '.':
      case '>':
        return 53;
      case '?':
      case '/':
        return 54;
      }
    }
    return -1;
  }
}
class MouseManager {
  private int x, y;
  private boolean[] button = new boolean[3]; //left = 0, right = 1, center = 2
  MouseManager() {
    button[0] = false;
    button[1] = false;
    x = 0;
    y = 0;
  }
  MouseManager(int tx, int ty) {
    x = tx;
    y = ty;
    button[0] = false;
    button[1] = false;
  }
  public void onMousePressed(int tx, int ty, int b1) {
    x = tx;
    y = ty;
    if (b1==37) {
      button[0] = true;
    } else if (b1==39) {
      button[1] = true;
    } else if (b1==3) {
      button[2] = true;
    }
  }
  public void onMouseReleased(int tx, int ty, int b1) {
    x = tx;
    y = ty;
    if (b1==37) {
      button[0] = false;
    } else if (b1==39) {
      button[1] = false;
    } else if (b1==3) {
      button[2] = false;
    }
  }
  public void onMouseMoved(int tx, int ty) {
    x = tx;
    y = ty;
  }
  public PVector getMouseLocation() {
    return new PVector(x, y);
  }
  public boolean getButtonPressed(int b) {
    return button[b];
  }
}
