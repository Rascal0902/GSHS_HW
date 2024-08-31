
/*
  Edge
*/

class Edge {
  int start, end, len;
  int distFromStart;
  PVector pos;
  PVector dragOffset;
  color c = color(0,0,0);
  boolean open;
  
  Edge(int s, int e, int l) {
    start = s;
    end = e;
    len = l;
    open = true;
    pos = new PVector(random(width-width/4), random(height-height/4));
    dragOffset = new PVector(0.0,0.0);
  }
  void printEdge() {
    println("(" + start + ", " + end + ", " + len + ")");
  }
  
  void drawEdge() {
    fill(c);
    ellipseMode(CENTER);
    ellipse(pos.x, pos.y, 30,30);
    fill(255);
    text(nf(end,0,0), pos.x-4, pos.y+5);
  }
  

}
