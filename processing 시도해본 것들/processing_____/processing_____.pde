float x1,y1,i,j,num1,size11,size21,angle1=0,fill11,fill12,fill13;
float x2,y2,num2,size12,size22,angle2=0,fill21,fill22,fill23;
float x3,y3,num3,size13,size23,angle3=0,fill31,fill32,fill33;
float x4,y4,num4,size14,size24,angle4=0,fill41,fill42,fill43;
float x5,y5,num5,size15,size25,angle5=0,fill51,fill52,fill53;
float x6,y6,num6,size16,size26,angle6=0,fill61,fill62,fill63;
float x7,y7,num7,size17,size27,angle7=0,fill71,fill72,fill73;
void setup(){
  size(1000,800);
  background(255);
}
void draw(){
  background(255);
  x1=200;
  y1=100;
  num1=10;
  size11=100;
  size21=10;
  fill11=100;
  fill12=100;
  fill13=0;
  x2=300;
  y2=230;
  num2=20;
  size12=200;
  size22=10;
  fill21=0;
  fill22=0;
  fill23=100;
  x3=400;
  y3=365;
  num3=10;
  size13=100;
  size23=10;
  fill31=255;
  fill32=255;
  fill33=255;
  x4=485;
  y4=290;
  num4=10;
  size14=90;
  size24=10;
  fill41=0;
  fill42=100;
  fill43=100;
  x5=300;
  y5=230;
  num5=10;
  size15=100;
  size25=10;
  fill51=50;
  fill52=50;
  fill53=50;
  x6=92;
  y6=400;
  num6=40;
  size16=400;
  size26=8;
  fill61=255;
  fill62=0; 
  fill63=0;
  x7=785;
  y7=95;
  num7=60;
  size17=600;
  size27=8;
  fill71=100;
  fill72=0;
  fill73=100;
  install(x1,y1,num1,size11,size21,angle1,fill11,fill12,fill13);
  install(x2,y2,num2,size12,size22,angle2,fill21,fill22,fill23);
  install(x3,y3,num3,size13,size23,angle3,fill31,fill32,fill33);
  install(x4,y4,num4,size14,size24,angle4,fill41,fill42,fill43);
  install(x5,y5,num5,size15,size25,angle5,fill51,fill52,fill53);
  install(x6,y6,num6,size16,size26,angle6,fill61,fill62,fill63);
  install(x7,y7,num7,size17,size27,angle7,fill71,fill72,fill73);
  angle1+=2;
  angle2+=-1;  
  angle3+=2;
  angle4+=-2;
  angle5+=-1;
  angle6+=0.25;
  angle7+=0.3333;
}
void install(float x,float y,float num,float size1,float size2,float angle,float fillx,float filly,float fillz){
  pushMatrix();
  translate(x,y);
  rotate(radians(angle));
  for(i=0;i<num;i++)
  { 
     rotate(radians(360/num));
     fill(fillx,filly,fillz);
     rect(size1/2-size2,-10,2*size2,20);
  }
  fill(fillx,filly,fillz);
  ellipse(0,0,size1,size1);
  popMatrix();
}
