class Node{
  float x,y;
  boolean visit=false;
  float n;
  Node(float x,float y,float n){
    this.x=x; this.y=y;this.n=n;
  }
  void display(){
    noStroke();
    if(this.visit){stroke(0,0,255);fill(0,0,255);}
    else{stroke(0);fill(0,0,0);}
    ellipse(x,y,50,50);
    textSize(30);stroke(255);fill(255); text((int)this.n,this.x,this.y+10);
  }
}
class Line{
  int n1,n2;
  float weight;
  
  Line(int n1,int n2,float weight){
    this.n1=n1;this.n2=n2;this.weight=weight;
  }
  void display(){
    fill(0,255,0);stroke(0,255,0);
    line(node[n1].x,node[n1].y,node[n2].x,node[n2].y);
    fill(0);stroke(0);
    text((int)weight,(node[n1].x+node[n2].x)/2,(node[n1].y+node[n2].y)/2);
  }
  PVector returnxy(){
    return new PVector(this.n1,this.n2);
  }
}
boolean linetrue(int n1,int n2){
  for(int i=0;i<lineend;i++){
    if(lin[i].returnxy()==new PVector(n1,n2)){
      return true;
    }
  }
  return false;
}
