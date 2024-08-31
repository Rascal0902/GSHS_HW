//아두이노 라이브러리
/*import processing.serial.*;import cc.arduino.*;Arduino arduino;int ledPin=13;*/
//소리 라이브러리 
import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.ugens.*;
Minim minim;AudioPlayer song;AudioMetaData meta;
String[] ca = new String[30]; // precaution에서의 주의사항을 나타내는 String 배열
String max1="T/He/Hu: 0 0 0";String min1="T/He/Hu: 0 0 0";String max2="T/He/Hu: 0 0 0";String min2="T/He/Hu: 0 0 0"; // 정상상태 측정할때의 max min값의 초기 설정 (T=온도 He=심박동수 Hu=습도)
float[] A = new float[6];     // check3D 함수를 위한 배열 A(잠시 저장해두는 용도)
float ceta=230,pi=140,size=1; // 초기 ceta pi size 지정 (ceta xz평면 회전) (pi yz 평면 회전) (size 그래프 사이즈)
float savex1=50,savey1=83,savex2=50,savey2=145,savex3=50,savey3=200,sz=0;  // 슬라이더 초기 위치 & 초기 설정(1번) 을 위한 함수의 진입여부를 결정하는 변수
float[][] pdata = new float [10000][6];int s=0;  // show()함수를 사용할때 필요한 배열 (어떤 점들을 나타낼 것인지 표시)
float[] data1 = new float [12500];
float maHe=0,miHe=0,maHu=0,miHu=0,maT=0,miT=0;
int window=1; // 값이 1이면 그래프를 2이면 precaution을 나타내는 창을 표시
PFont font;   // precaution에서의 한글을 나타내기 위한 Font설정

void setup(){size(1500,800);background(0);surface.setTitle("heart beat checking");surface.setLocation(230, 100);font=createFont("바탕체",32); //창의 제목+크기+위치+font를 결정
             /*arduino = new Arduino(this, Arduino.list()[0], 57600);arduino.pinMode(ledPin, Arduino.OUTPUT);*/ // 아두이노와 연결
             minim = new Minim(this); //새로운 음악 파일 객체 형성
             song = minim.loadFile("soundfilename.mp3"); //음악 설정
            }
void draw(){
  if(sz==0){setangle();makecoordinate();setupcheck();sz=1;}   // 한번만 도는 함수들을 넣는다 
  if(window==1){if(mouseButton==LEFT){setangle();makecoordinate();} //window==1이면 그래프를 표시  // 마우스 왼쪽 버튼을 누르면 각도 설정해준다 + 좌표계 나타내는 함수 
  make_bar();rebar(); // bar를 나타낸다. 
  stroke(#08B9FC);fill(#08B9FC);rect(250,20,130,20);fill(0);stroke(0);textSize(20);text("Precautions",259,38);strokeWeight(5); // precaution 버튼과 이를 눌렀을때 윈도우를 바꾸게 하는 코드
  if((mouseX>=250)&&(mouseX<=380)&&(mouseY>=20)&&(mouseY<=40)&&(mouseButton==LEFT)){window=2;}
  stroke(#FC08E5);fill(#FC08E5);rect(250,240,75,20);fill(0);stroke(0);textSize(20);text("check",259,258);strokeWeight(5); // check1()함수를 실행시킴으로서 정상 상태의 요소들을 측정한다. 
  if((mouseX>=250)&&(mouseX<=380)&&(mouseY>=240)&&(mouseY<=260)&&(mouseButton==LEFT)){check1();}
  stroke(#FC08E5);fill(#FC08E5);rect(250,380,75,20);fill(0);stroke(0);textSize(20);text("check",259,398);strokeWeight(5); // check2()함수를 실행시킴으로서 실제로 거짓말인지 확인할 요소들을 측정한다. 
  if((mouseX>=250)&&(mouseX<=380)&&(mouseY>=380)&&(mouseY<=400)&&(mouseButton==LEFT)){check2();}
  Cuboid((maT+miT)/2,(maHe+miHe)/2,(maHu+miHu)/2,(maT-miT)/2,(maHe-miHe)/2,(maHu-miHu)/2,0,255,0,0,1); // check1()함수 를 실행시켰을때 정상 상태의 값들이 나올텐데 
  show(); // 그래프에 데이터 표시하기 
  }
  if(window==2){ // precaution 창을 나타나게 해준다.
    background(255); //배경을 흰색으로 초기화 해준다.
    fill(0); rect(0,0,1500,50);fill(255);textSize(40);text("Precautions",50,45);strokeWeight(5);fill(0); //배경을 나타내준다
    for(int i=0;i<9;i++){ 
      textFont(font, 12); // 한글을 나타내는데 도움을 준다.
      textSize(30);text(ca[i],50,145+i*40);strokeWeight(5);} //주의사항을 나타내준다 이 배열은 setup()에서 결정된다. 
    stroke(#08B9FC);fill(#08B9FC);rect(1350,720,100,20);fill(0);stroke(0);textSize(20);text("go back",1359,738);strokeWeight(5); //그래프화면으로 다시 돌아가기 위하여 버튼을 하나 더 만든다.
  if((mouseX>=1350)&&(mouseX<=1450)&&(mouseY>=720)&&(mouseY<=740)&&(mouseButton==LEFT)){window=1;}}}
  //pdata 즉 점에 관련된 정보를 stack 형태로 push pop을 한다.
void dpush(float x,float y,float z,float R,float G,float B){ 
  pdata[s][0]=x;pdata[s][1]=y;pdata[s][2]=z;pdata[s][3]=R;pdata[s][4]=G;pdata[s][5]=B;s++;return;}
void dclear(){for(int i=0;i<s;i++){pdata[s][0]=0;pdata[s][1]=0;pdata[s][2]=0;pdata[s][3]=0;pdata[s][4]=0;pdata[s][5]=0;}s=0;return;}
void show(){for(int i=0;i<s;i++){point3D_RGB(pdata[i][0],pdata[i][1],pdata[i][2],pdata[i][3],pdata[i][4],pdata[i][5],2,0);}return;} //data에 있는 정보를 이용하여 점을 표시한다.
