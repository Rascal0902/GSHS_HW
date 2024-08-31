float t,move=0,app=0.1;
float[] M=  new float[100];
float[][] H = new float[1000][1000];
float maxmin,min;
float[] A = new float[6];
float ceta,pi;
//check3D(float x,float y,float z)
//point3D(float x,float y,float z)
//point3D_RGB(float x,float y,float z,float R,float G,float B,float st)
//Bezier_line3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,float x5,float y5,float z5)
//line3D_RGB(float x,float y,float z,float w,float m,float n,float R,float G,float B)
//Bezier_move3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,float x5,float y5,float z5)
//makeBezier(float start,float last,float r,float n)
//goBezier(float start,float last,float n,float r,float num)
//nogoBezier(float start,float last,float n,float r,float num)
//noBezier(float x0,float y0,float x1,float y1,float x2,float y2)
//circle2D(float r,float n,float start,float last)
//Bezier3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2, float num)
//Bezier2D(float x0,float y0,float x1,float y1,float x2,float y2,float num)
//Bezier_line2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5)
//Bezier_move2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5)
//Bezier_move_change2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5,float k,float R,float G,float B,float m)
//Housedorf(float r,float start,float last,float x0,float y0,float x1,float y1,float x2,float y2,float num)
//bar(float x,float y1,float y2)
//circles()
//spiral_curve()
//coordinate3D()
void setup()
{
  size(1000,1000);
  background(255);
}
void draw()
{
  if(mouseButton==LEFT)
  {
    ceta=mouseX/1000.0*360.0;
    pi=mouseY/1000.0*360.0;
    background(0);
    strokeWeight(5);
    stroke(255);
    textSize(10);
    text("pi=",85,100);
    text("ceta=",85,120);
    text(pi,100,100);
    text(ceta,110,120);
  }
  coordinate3D();
  Bezier3D(100,120,250,250,200,30,10,120,30,1);
  Bezier3D(-100,-120,-250,-250,-200,-30,-10,-120,-30,2);
  Bezier_line3D(100,120,250,250,200,30,10,120,30,-100,-120,-250,-250,-200,-30,-10,-120,-30);
  Bezier_move3D(100,120,250,250,200,30,10,120,30,-100,-120,-250,-250,-200,-30,-10,-120,-30);
  //spiral_curve();
  //circles();
  // Bezier move 3D();
  //bar(800,100,800);
  //circle2D(100,0,0,360);
  //Bezier2D(300,100,450,50,600,100,1);
  //Housedorf(100,220,320,300,100,450,50,600,100);
  //makeBezier(0,360,100,0);
  // Bezier2D(300,100,150,250,400,300,1);
  // Bezier2D(700,200,850,250,800,400,2);
  // Bezier_line2D(300,100,150,250,400,300,700,200,850,250,800,400);
  //Bezier_move2D(300,100,150,250,400,300,700,200,850,250,800,400);
  /*Bezier_move_change2D(300,100,400,25,500,100,450,900,400,700,500,800,move,0,0,0,0);
  Bezier_move_change2D(300,100,500,175,500,100,450,900,500,1000,500,800,move,0,0,0,0);
  Bezier_move_change2D(300,100,400,25,500,100,450,900,400,700,500,800,move-0.01,255,255,255,1);
  Bezier_move_change2D(300,100,500,175,500,100,450,900,500,1000,500,800,move-0.01,255,255,255,1);
  if(move<=1)
  {
   move+=0.002;
  }
  else
  {
    background(255);
   move=0;
  } */
}
void Bezier_line3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,float x5,float y5,float z5)
{
  float z,w,d,e,t=0,u,v;
    for(t=0;t<=1;t+=0.2)
  {
    z=t*t*x0+2*t*(1-t)*x1+(1-t)*(1-t)*x2;
    w=t*t*y0+2*t*(1-t)*y1+(1-t)*(1-t)*y2;
    d=t*t*z0+2*t*(1-t)*z1+(1-t)*(1-t)*z2;
    u=t*t*x3+2*t*(1-t)*x4+(1-t)*(1-t)*x5;
    v=t*t*y3+2*t*(1-t)*y4+(1-t)*(1-t)*y5;
    e=t*t*z3+2*t*(1-t)*z4+(1-t)*(1-t)*z5;
    strokeWeight(2);
    line3D_RGB(z,w,d,u,v,e,0,255,255);
  }
}
void Bezier_move3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3,float x4,float y4,float z4,float x5,float y5,float z5)
{
  float i,t=0,u0,v0,w0,u1,v1,w1,u2,v2,w2,u,v,w;
  for(i=0.1;i<=0.9;i+=0.1)
  {
    u0=(1-i)*x0+i*x3;
    u1=(1-i)*x1+i*x4;
    u2=(1-i)*x2+i*x5;
    v0=(1-i)*y0+i*y3;
    v1=(1-i)*y1+i*y4;
    v2=(1-i)*y2+i*y5;
    w0=(1-i)*z0+i*z3;
    w1=(1-i)*z1+i*z4;
    w2=(1-i)*z2+i*z5;
    stroke(45,196,182);
    strokeWeight(5);
    //point(u0,v0);
    //point(u1,v1);
    //point(u2,v2);
      for(t=0;t<=1;t+=0.005)
    {
      u=t*t*u0+2*t*(1-t)*u1+(1-t)*(1-t)*u2;
      v=t*t*v0+2*t*(1-t)*v1+(1-t)*(1-t)*v2;
      w=t*t*w0+2*t*(1-t)*w1+(1-t)*(1-t)*w2;
      stroke(28,234,109);
      strokeWeight(10);
      point3D_RGB(u,v,w,255,255,0,5);
    }
  }
}
void makeBezier(float start,float last,float r,float n)
{
  //circle2D(r,2,start,(start+last)/2);
  //circle2D(r,2,(start+last)/2,last);
  goBezier(start,(start+last)/2,0,r,n);
  goBezier((start+last)/2,last,1,r,n);
  //circle2D(100,0,0,360);
  //error check function
  if(M[(int)n]>app)
  {
    nogoBezier(start,(start+last)/2,0,r,n);
    nogoBezier((start+last)/2,last,1,r,n);
    makeBezier(start,(start+last)/2,r,n+1);
    makeBezier((start+last)/2,last,r,n+1);
  }
}
void nogoBezier(float start,float last,float n,float r,float num)
{
  float gamma1x,gammahalfx,gamma0x,beta1x,betahalfx,beta0x;
  float gamma1y,gammahalfy,gamma0y,beta1y,betahalfy,beta0y;
  gamma0x=500+r*cos(radians(start));
  gamma0y=400+r*sin(radians(start));
  gamma1x=500+r*cos(radians(last));
  gamma1y=400+r*sin(radians(last));
  gammahalfx=500+r*cos(radians((start+last)/2));
  gammahalfy=400+r*sin(radians((start+last)/2));
  beta0x=500+r*cos(radians(start));
  beta0y=400+r*sin(radians(start));
  beta1x=500+r*cos(radians(last));
  beta1y=400+r*sin(radians(last));
  betahalfx=2*gammahalfx-(gamma0x+gamma1x)/2;
  betahalfy=2*gammahalfy-(gamma0y+gamma1y)/2;
  noBezier(beta0x,beta0y,betahalfx,betahalfy,beta1x,beta1y);
}
void noBezier(float x0,float y0,float x1,float y1,float x2,float y2)
{
   float z,w,t=0;
  for(t=0;t<=1;t+=0.005)
  {
    z=t*t*x0+2*t*(1-t)*x1+(1-t)*(1-t)*x2;
    w=t*t*y0+2*t*(1-t)*y1+(1-t)*(1-t)*y2;
    stroke(255);
    strokeWeight(6);
    point(z,w);
  }
}
void goBezier(float start,float last,float n,float r,float num)
{
  float gamma1x,gammahalfx,gamma0x,beta1x,betahalfx,beta0x;
  float gamma1y,gammahalfy,gamma0y,beta1y,betahalfy,beta0y;
  gamma0x=500+r*cos(radians(start));
  gamma0y=400+r*sin(radians(start));
  gamma1x=500+r*cos(radians(last));
  gamma1y=400+r*sin(radians(last));
  gammahalfx=500+r*cos(radians((start+last)/2));
  gammahalfy=400+r*sin(radians((start+last)/2));
  beta0x=500+r*cos(radians(start));
  beta0y=400+r*sin(radians(start));
  beta1x=500+r*cos(radians(last));
  beta1y=400+r*sin(radians(last));
  betahalfx=2*gammahalfx-(gamma0x+gamma1x)/2;
  betahalfy=2*gammahalfy-(gamma0y+gamma1y)/2;
  point(betahalfx,betahalfy);
  Bezier2D(beta0x,beta0y,betahalfx,betahalfy,beta1x,beta1y,n);
  Housedorf(100,start,last,beta0x,beta0y,betahalfx,betahalfy,beta1x,beta1y,num);
}
void circle2D(float r,float n,float start,float last)
{
  strokeWeight(5);
  stroke(0);
  fill(255);
  ellipse(500,400,2*r,2*r);
  if(n>0)
  {
    float i;
    for(i=0;i<=n;i++)
    {
      strokeWeight(10);
      stroke(229,37,105);
      point(500+r*cos(radians(start+(last-start)/n*i)),400+r*sin(radians(start+(last-start)/n*i)));
    }
  }
}
void Bezier2D(float x0,float y0,float x1,float y1,float x2,float y2,float num)
{
  strokeWeight(6);
  stroke(#3FFF00);
  point(x0,y0);
  fill(0,0,0);
  textSize(20);
  //text("P0_",x0+10,y0-20);
  //text((int)num,x0+45,y0-20);
  point(x1,y1);
  fill(0,0,0);
  textSize(20);
  //text("P1_",x1+10,y1-20);
  //text(( int)num,x1+45,y1-20);
  point(x2,y2);
  fill(0,0,0);
  textSize(20);
  //text("P2_",x2+10,y2-20);
  //text((int)num,x2+45,y2-20);
  float z,w,t=0;
  for(t=0;t<=1;t+=0.005)
  {
    z=t*t*x0+2*t*(1-t)*x1+(1-t)*(1-t)*x2;
    w=t*t*y0+2*t*(1-t)*y1+(1-t)*(1-t)*y2;
    stroke(255,0,0);
    strokeWeight(5);
    point(z,w);
  }
}
void Bezier_line2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5)
{
  float z,w,t=0,u,v;
    for(t=0;t<=1;t+=0.2)
  {
    z=t*t*x0+2*t*(1-t)*x1+(1-t)*(1-t)*x2;
    w=t*t*y0+2*t*(1-t)*y1+(1-t)*(1-t)*y2;
    u=t*t*x3+2*t*(1-t)*x4+(1-t)*(1-t)*x5;
    v=t*t*y3+2*t*(1-t)*y4+(1-t)*(1-t)*y5;
    stroke(239,247,7);
    strokeWeight(2);
    line(z,w,u,v);
  }
}
void Bezier_move2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5)
{
  float i,t=0,u0,v0,u1,v1,u2,v2,u,v;
  for(i=0;i<=1.01;i+=0.1)
  {
    u0=(1-i)*x0+i*x3;
    u1=(1-i)*x1+i*x4;
    u2=(1-i)*x2+i*x5;
    v0=(1-i)*y0+i*y3;
    v1=(1-i)*y1+i*y4;
    v2=(1-i)*y2+i*y5;
    stroke(45,196,182);
    strokeWeight(5);
    //point(u0,v0);
    //point(u1,v1);
    //point(u2,v2);
      for(t=0;t<=1;t+=0.005)
    {
      u=t*t*u0+2*t*(1-t)*u1+(1-t)*(1-t)*u2;
      v=t*t*v0+2*t*(1-t)*v1+(1-t)*(1-t)*v2;
      stroke(28,234,109);
      strokeWeight(10);
      point(u,v);
    }
  }
}
void Bezier_move_change2D(float x0,float y0,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5,float k,float R,float G,float B,float m)
{
  float i,t=0,u0,v0,u1,v1,u2,v2,u,v;
  i=k;
    u0=(1-i)*x0+i*x3;
    u1=(1-i)*x1+i*x4;
    u2=(1-i)*x2+i*x5;
    v0=(1-i)*y0+i*y3;
    v1=(1-i)*y1+i*y4;
    v2=(1-i)*y2+i*y5;
    stroke(R,G,B);
    strokeWeight(5);
   // point(u0,v0);
   // point(u1,v1);
    //point(u2,v2);
    if(m==0)
    {
       for(t=0.01;t<=0.99;t+=0.005)
    {
      u=t*t*u0+2*t*(1-t)*u1+(1-t)*(1-t)*u2;
      v=t*t*v0+2*t*(1-t)*v1+(1-t)*(1-t)*v2;
      stroke(R,G,B);
      strokeWeight(8);
      point(u,v);
    }
    }
    else
    {
      for(t=-0.1;t<=1.1;t+=0.005)
    {
      u=t*t*u0+2*t*(1-t)*u1+(1-t)*(1-t)*u2;
      v=t*t*v0+2*t*(1-t)*v1+(1-t)*(1-t)*v2;
      stroke(R,G,B);
      strokeWeight(10);
      point(u,v);
    }
    }
  
}
void Housedorf(float r,float start,float last,float x0,float y0,float x1,float y1,float x2,float y2,float num)
{
  float t=start,d1=(last-start)/10,k=0,d2=0.1;
  int i,j;
  for(i=0;i<10;i++)
  {
    k=d2*i;
    for(j=0;j<10;j++)
    {
      H[i][j]=dist(500+r*cos(radians(t)),400+r*sin(radians(t)),x0*(1-k)*(1-k)+2*k*(1-k)*x1+k*k*x2,y0*(1-k)*(1-k)+2*k*(1-k)*y1+k*k*y2);
      //stroke(#FFDA08);
      //line(500+r*cos(radians(t)),400+r*sin(radians(t)),x0*(1-k)*(1-k)+2*k*(1-k)*x1+k*k*x2,y0*(1-k)*(1-k)+2*k*(1-k)*y1+k*k*y2);
      //i circle j Bezier
      t+=d1;
      if(min>=H[i][j])
      {
        min=H[i][j];
      }
    }
    t=start;
    if(maxmin<=min)
    {
      maxmin=min;
    }
    min=100000;
  }
  M[(int)num]=maxmin;
  maxmin=0;
  textSize(30);
  stroke(255);
  fill(255);
  rect(200,700,900,900);
  stroke(0);
  fill(0);
  text("Hausdorff distance=",300,800);
  text(M[(int)num],600,800);
}
void bar(float x,float y1,float y2)
{
  if(mouseButton==LEFT)
  {
    //800,100,800
    if((mouseY<=800)&&(mouseY>=100))
    {
      app=(mouseY-100)/30+3;
       fill(255);
       strokeWeight(0);
       rect(x-10,y1-10,20,y2-y1+20);
       fill(100);
       rect(x-5,y1,10,y2-y1);
       fill(255,0,0);
       ellipse(x,mouseY,15,15);
       fill(0,0,0);
       textSize(15);
       text("error check=",700,50);
       fill(255);
       rect(800,30,60,20);
       fill(0);
       text(app,800,50);
    }
  }
}
void circles()
{
  float i,j;
  for(i=0;i<200;i+=20)
  {
    for(j=0;j<360;j+=1)
    {
      point3D_RGB(i*cos(radians(j)),0,i*sin(radians(j)),255,0,0,3);
    }
  }
  
}
void spiral_curve()
{
  float i;
  for(i=-1;i<=1;i+=0.001)
  {
    point3D_RGB(30*cos(radians(i*1000)),i*100,30*sin(radians(i*1000)),255,200-200*i,i*200,5);
  }
}
void coordinate3D()
{
  line3D_RGB(-300,0,0,300,0,0,255,255,255);
  line3D_RGB(0,-300,0,0,300,0,255,255,255);
  line3D_RGB(0,0,-300,0,0,300,255,255,255);
  textSize(20);
  stroke(255);
  fill(255,255,255);
  check3D(310,0,0);
  text("+x",500+A[0],500+A[1]);
  check3D(-310,0,0);
  text("-x",500+A[0],500+A[1]);
  check3D(0,310,0);
  text("+y",500+A[0],500+A[1]);
  check3D(0,-310,0);
  text("-y",500+A[0],500+A[1]);
  check3D(0,0,310);
  text("+z",500+A[0],500+A[1]);
  check3D(0,0,-310);
  text("-z",500+A[0],500+A[1]);
}
void point3D(float x,float y,float z)
{
  stroke(255);
  A[0]=x*sin(radians(ceta))-z*sin(radians(ceta));
  A[1]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));
  strokeWeight(10);
  stroke(255);
  point(500+A[0],500+A[1]);
}
void point3D_RGB(float x,float y,float z,float R,float G,float B,float st)
{
  stroke(255);
  A[0]=x*sin(radians(ceta))-z*sin(radians(ceta));
  A[1]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));
  strokeWeight(st);
  stroke(R,G,B);
  point(500+A[0],500+A[1]);
}
void line3D_RGB(float x,float y,float z,float w,float m,float n,float R,float G,float B)
{
  stroke(255);
  A[2]=x*sin(radians(ceta))-z*sin(radians(ceta));
  A[3]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));
  A[4]=w*sin(radians(ceta))-n*sin(radians(ceta));
  A[5]=m*cos(radians(pi))-w*sin(radians(pi))*sin(radians(ceta))-n*cos(radians(ceta))*sin(radians(pi));
  strokeWeight(5);
  stroke(R,G,B);
  line(500+A[2],500+A[3],500+A[4],500+A[5]);
}
void check3D(float x,float y,float z)
{
  stroke(255);
  A[0]=x*sin(radians(ceta))-z*sin(radians(ceta));
  A[1]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));
}
void Bezier3D(float x0,float y0,float z0,float x1,float y1,float z1,float x2,float y2,float z2, float num)
{
  strokeWeight(6);
  stroke(#08FF16);
  point3D(x0,y0,z0);
  fill(255,255,255);
  textSize(20);
  check3D(x0+10,y0-20,z0-20);
  text("P0_",500+A[0],500+A[1]);
  text((int)num,500+A[0]+35,500+A[1]);
  strokeWeight(6);
  stroke(#08FF16);
  point3D(x1,y1,z1);
  fill(255,255,255);
  textSize(20);
  check3D(x1+10,y1-20,z1-20);
  text("P1_",500+A[0],500+A[1]);
  text((int)num,500+A[0]+35,500+A[1]);
  strokeWeight(6);
  stroke(#08FF16);
  point3D(x2,y2,z2);
  fill(255,255,255);
  textSize(20);
  check3D(x2+10,y2-20,z2-20);
  text("P2_",500+A[0],500+A[1]);
  text((int)num,500+A[0]+35,500+A[1]);
  float z,w,k,t=0;
  for(t=0;t<=1;t+=0.005)
  {
    z=t*t*x0+2*t*(1-t)*x1+(1-t)*(1-t)*x2;
    w=t*t*y0+2*t*(1-t)*y1+(1-t)*(1-t)*y2;
    k=t*t*z0+2*t*(1-t)*z1+(1-t)*(1-t)*z2;
    point3D_RGB(z,w,k,255,0,0,5);
  }
}
