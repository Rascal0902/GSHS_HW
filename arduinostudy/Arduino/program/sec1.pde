void setupcheck(){ // 초기 설정 함수이다. 여기에서 주의사항에 대한 정보를 업데이트 한다.
     ca[0]="이 키트는 흥분한 상태를 측정하는 키트이며 스트레스 해소용 키트가 아닙니다.";
     ca[1]="키트를 소중히 대해주세요.";
     ca[2]="프로세싱과 연동되어 사용되는 키트이기 때문에 프로세싱을 컴퓨터에 설치한";
     ca[3]="뒤에 사용하셔야 합니다.";
     ca[4]="맨 처음 사용하실 때에는 편안한 상태에서 row 데이터를 얻기 위하여 한번";
     ca[5]="심박수와 호흡을 측정하여 주세요.";
     ca[6]="사용자가 흥분한 것 같은 상황에 키트를 사용하시면, 키트가 사용자의 심박수와";
     ca[7]="호흡 특이성을 측정하여 3D그래프로 나타내 주고, 특정 기준을 넘기게 된다면";
     ca[8]="부저음이 울립니다. 측정하는 동안 마음을 안정시키는 음악을 들려드리니 흥분을 없애주세요. ";
}
void makecoordinate(){ //좌표계를 나타낸다.
  line3D(-350,0,0,350,0,0,size,255,255,255,5);line3D(0,-350,0,0,350,0,size,255,255,255,5);line3D(0,0,-350,0,0,350,size,255,255,255,5); //축 3개를 표시한다.
  textSize(20);stroke(255);fill(255);
  check3D(360,0,0,size);text("+T",950+A[0],400+A[1]);check3D(-360,0,0,size);text("-T",950+A[0],400+A[1]);
  check3D(0,360,0,size);text("+He",950+A[0],400+A[1]);check3D(0,-360,0,size);text("-He",950+A[0],400+A[1]);
  check3D(0,0,360,size);text("+Hu",950+A[0],400+A[1]);check3D(0,0,-360,size);text("-Hu",950+A[0],400+A[1]);fill(0);stroke(0);} // 축의 어느 방향이 어느쪽을 의마하는지 표시한다. x: T(온도) , y: He(심박동수), z: Hu(습도)
//그래프에 있는 3개의 슬라이더를 표시한다.
void rebar(){if(window==1){strokeWeight(5);   // 슬라이더의 점의 위치를 그래프의 이동에 따라 나타낸다.
   if((mouseX>=400)&&(mouseY>=0)&&(mouseY<=800)&&(mouseX<=1500)){
       fill(0);rect(50-10,83-10,300+20,20);fill(100);rect(50,83-5,300,10);fill(255,0,0);ellipse((mouseY/800.0)*300+50,83,15,15);
       fill(0);rect(50-10,145-10,300+20,20);fill(100);rect(50,145-5,300,10);fill(255,0,0);ellipse(((mouseX-400)/1100.0)*300+50,145,15,15);
       fill(0);rect(50-10,200-10,300+20,20);fill(100);rect(50,200-5,300,10);fill(255,0,0);ellipse(size/1.5*300+50,200,15,15);}
  else{fill(0);rect(50-10,83-10,300+20,20);fill(100);rect(50,83-5,300,10);fill(255,0,0);ellipse((pi/360)*300+50,83,15,15);
       fill(0);rect(50-10,145-10,300+20,20);fill(100);rect(50,145-5,300,10);fill(255,0,0);ellipse(ceta/360.0*300+50,145,15,15);
       fill(0);rect(50-10,200-10,300+20,20);fill(100);rect(50,200-5,300,10);fill(255,0,0);ellipse(size/1.5*300+50,200,15,15);}}}
void make_bar(){if(window==1){bar1(83,50,350);bar2(145,50,350);bar3(200,50,350);}}  //슬라이더에 있는 점을 욺겨도 위치가 변경이 되도록 설정
//pi ceta size 의 3개의 슬라이더를 나타낸다.
void bar1(float y,float x1,float x2){savey1=y;fill(0);rect(x1-10,y-10,x2-x1+20,20);fill(100);rect(x1,y-5,x2-x1,10);fill(255,0,0);ellipse(savex1,savey1,15,15);
  if(mouseButton==LEFT){if((mouseX<=x2)&&(mouseX>=x1)&&(mouseY>y-10)&&(mouseY<y+10)){savex1=mouseX;pi=(savex1-x1)/(x2-x1)*360;}}strokeWeight(5);}
void bar2(float y,float x1,float x2){savey2=y;fill(0);rect(x1-10,y-10,x2-x1+20,20);fill(100);rect(x1,y-5,x2-x1,10);fill(255,0,0);ellipse(savex2,savey2,15,15);
  if(mouseButton==LEFT){if((mouseX<=x2)&&(mouseX>=x1)&&(mouseY>y-10)&&(mouseY<y+10)){savex2=mouseX;ceta=(savex2-x1)/(x2-x1)*360;}}strokeWeight(5);}
void bar3(float y,float x1,float x2){savey3=y;fill(0);rect(x1-10,y-10,x2-x1+20,20);fill(100);rect(x1,y-5,x2-x1,10);fill(255,0,0);ellipse(savex3,savey3,15,15);
  if(mouseButton==LEFT){if((mouseX<=x2)&&(mouseX>=x1)&&(mouseY>y-10)&&(mouseY<y+10)){savex3=mouseX;size=(savex3-x1)/(x2-x1)*1.5;}}strokeWeight(5);}
  //그래프위의 커서에 따라 각이 어떻게 변하는지 구해서 나타내준다.+ 배경의 기타 기능을 나타내준다.
void setangle(){background(0);fill(#00FFBD);rect(0,0,400,800);textSize(20); //그래프의 배경을 나타낸다.
    if((mouseX>=400)&&(mouseY>=0)&&(mouseY<=800)&&(mouseX<=1500)){ceta=(mouseX-400)/1100.0*360.0;pi=mouseY/800.0*360.0;}
    fill(0);text("angle",45,30);text("phi=",45,60);text("theta=",45,120);text("size=",45,180);fill(0);
    text(pi,85,60);text(ceta,105,120);text(size,100,180);  
    text("normal Heartbeat",45,260);text("max",45,300);text("min",45,340);text("checking heartbeat",45,400);text("max",45,440);text("min",45,480);  // 배경의 정보들을 텍스트로 표시한다.
    text(max1,95,300);text(min1,95,340);text(max2,95,440);text(min2,95,480);
    fill(0);stroke(0);}
void mouseWheel(MouseEvent event) {if(window==1){ //마우스 휠의 변화로 그래프의 확대 축소를 조절할 수 있게 설정한다. 
    if(((mouseX>=400)&&(mouseY>=0)&&(mouseY<=800)&&(mouseX<=1500))&&(size>=0.1)&&(size<=1.49)){textSize(20);
    float e = event.getCount()*0.01;size-=e;setangle();strokeWeight(5);fill(0);makecoordinate();strokeWeight(5);fill(0);}strokeWeight(5);fill(0);make_bar();rebar();}}
void point3D_RGB(float x,float y,float z,float R,float G,float B,float st,float siz){if(siz==0){siz=size;}   //점을 나타내주는 함수이다.
  A[0]=x*cos(radians(ceta))-z*sin(radians(ceta));A[0]=A[0]*siz;A[1]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));A[1]=A[1]*siz;
  strokeWeight(st);stroke(R,G,B);point(950+A[0],400+A[1]);stroke(0);strokeWeight(5);}
void line3D(float x,float y,float z,float w,float m,float n,float siz,float R,float G,float B,float strokeweight){if(siz==0){siz=size;} //선을 나타내주는 함수이다.
  A[2]=x*cos(radians(ceta))-z*sin(radians(ceta));A[2]=A[2]*siz;
  A[3]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));A[3]=A[3]*siz;
  A[4]=w*cos(radians(ceta))-n*sin(radians(ceta));A[4]=A[4]*siz;
  A[5]=m*cos(radians(pi))-w*sin(radians(pi))*sin(radians(ceta))-n*cos(radians(ceta))*sin(radians(pi));A[5]=A[5]*siz;
  strokeWeight(strokeweight);stroke(R,G,B);line(950+A[2],400+A[3],950+A[4],400+A[5]);stroke(0);strokeWeight(5);}
void check3D(float x,float y,float z,float siz){if(siz==0){siz=size;} //어느 점에 체크가 될지 미리 구해서 A배열에 저장해준다. (2차원 사영)
  A[0]=x*cos(radians(ceta))-z*sin(radians(ceta));A[0]=A[0]*siz;
  A[1]=y*cos(radians(pi))-x*sin(radians(pi))*sin(radians(ceta))-z*cos(radians(ceta))*sin(radians(pi));A[1]=A[1]*siz;}
void Cuboid(float x0,float y0,float z0,float drx,float dry,float drz,int R,int G,int B,float siz,float strokeweight) //직육면체를 나타내주는 함수이다.
{if(siz==0){siz=size;}point3D_RGB(x0,y0,z0,255,0,207,8,siz);
   point3D_RGB(x0+drx,y0+dry,z0+drz,0,0,255,8,siz);point3D_RGB(x0+drx,y0+dry,z0-drz,0,0,255,8,siz);point3D_RGB(x0+drx,y0-dry,z0+drz,0,0,255,8,siz);point3D_RGB(x0-drx,y0+dry,z0+drz,0,0,255,8,siz);
   point3D_RGB(x0-drx,y0-dry,z0+drz,0,0,255,8,siz);point3D_RGB(x0+drx,y0-dry,z0-drz,0,0,255,8,siz);point3D_RGB(x0-drx,y0+dry,z0-drz,0,0,255,8,siz);point3D_RGB(x0-drx,y0-dry,z0-drz,0,0,255,8,siz);
   line3D(x0+drx,y0+dry,z0+drz,x0+drx,y0+dry,z0-drz,siz,R,G,B,strokeweight);line3D(x0+drx,y0+dry,z0+drz,x0+drx,y0-dry,z0+drz,siz,R,G,B,strokeweight);
   line3D(x0+drx,y0+dry,z0+drz,x0-drx,y0+dry,z0+drz,siz,R,G,B,strokeweight);line3D(x0-drx,y0-dry,z0+drz,x0-drx,y0+dry,z0+drz,siz,R,G,B,strokeweight);
   line3D(x0-drx,y0-dry,z0+drz,x0+drx,y0-dry,z0+drz,siz,R,G,B,strokeweight);line3D(x0-drx,y0+dry,z0-drz,x0+drx,y0+dry,z0-drz,siz,R,G,B,strokeweight);
   line3D(x0-drx,y0+dry,z0-drz,x0-drx,y0+dry,z0+drz,siz,R,G,B,strokeweight);line3D(x0+drx,y0-dry,z0-drz,x0+drx,y0+dry,z0-drz,siz,R,G,B,strokeweight);
   line3D(x0+drx,y0-dry,z0-drz,x0+drx,y0-dry,z0+drz,siz,R,G,B,strokeweight);line3D(x0-drx,y0-dry,z0-drz,x0+drx,y0-dry,z0-drz,siz,R,G,B,strokeweight);
   line3D(x0-drx,y0-dry,z0-drz,x0-drx,y0+dry,z0-drz,siz,R,G,B,strokeweight);line3D(x0-drx,y0-dry,z0-drz,x0-drx,y0-dry,z0+drz,siz,R,G,B,strokeweight);}
