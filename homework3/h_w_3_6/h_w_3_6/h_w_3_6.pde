
Box mybox;
float theta = 0.3;
float c = 0.1;
void setup(){
  size(1000, 500);
  mybox = new Box(width, height-width*tan(theta), 0, 0, 0.5);
}


void draw(){
  float mu=0.1;
  background(255);
  line(0, height, width, height-width*tan(theta));
  //println(height-width*tan(theta));
  PVector gravity = new PVector(-0.3*sin(theta)*cos(theta),0.3*sin(theta)*sin(theta));
  gravity.mult(mybox.m);
  PVector friction = new PVector(-mu*-0.3*cos(theta),-mu*0.3*sin(theta));
  friction.mult(mybox.m);
  
  
  float fg= gravity.mag();
  mybox.applyForce(gravity); //gravity
  mybox.applyForce(friction);
  
  mybox.display(theta);
  mybox.update();
  
}
