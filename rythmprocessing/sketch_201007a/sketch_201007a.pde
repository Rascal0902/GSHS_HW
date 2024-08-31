import processing.sound.*;
SoundFile file;
String audioName = "Music.mp3";
String path;
float[] t = new float[20000];
float[] angle = new float [122];
float[] v = new float [122];
float[] vx = new float [122];
float[] vy = new float [122];
float[] x = new float [122];
float[] y = new float [122];
float[] r = new float [122];
float[] g = new float [122];
float[] b = new float [122];
float R=10.0;
void setup(){
  path = sketchPath(audioName);
  file = new SoundFile(this,path);
  //file.play();
  size(1000,1000);
  frameRate(78);
  background(0);
  textSize(30);
  for(int i=1;i<122;i++){
    angle[i]=random(0,2*PI);
    v[i]=random(0.1,0.15);
    vx[i]=cos(angle[i])*v[i];
    vy[i]=sin(angle[i])*v[i];
    x[i]=400+20*(i%11);
    y[i]=400+20*((i-1)/11);
    r[i]=random(0,255.99);
    g[i]=random(0,255.99);
    b[i]=random(0,255.99);
  }
  int tmp=720,tmp2=1092,tmp4=5396;
  t[60]=t[60+tmp]=t[60+2*tmp]=(int)random(1,4.99);
  t[75]=t[75+tmp]=t[75+2*tmp]=(int)random(1,4.99);
  t[90]=t[90+tmp]=t[90+2*tmp]=(int)random(1,4.99);
  t[105]=t[105+tmp]=t[105+2*tmp]=(int)random(1,4.99);
  t[120]=t[120+tmp]=t[120+2*tmp]=(int)random(1,4.99);
  t[135]=t[135+tmp]=t[135+2*tmp]=(int)random(1,4.99);
  t[150]=t[150+tmp]=t[150+2*tmp]=(int)random(1,4.99);
  t[180]=t[180+tmp]=t[180+2*tmp]=(int)random(1,4.99);
  t[210]=t[210+tmp]=t[210+2*tmp]=(int)random(1,4.99);
  t[240]=t[240+tmp]=t[240+2*tmp]=(int)random(1,4.99);
  t[255]=t[255+tmp]=t[255+2*tmp]=(int)random(1,4.99);
  t[270]=t[270+tmp]=t[270+2*tmp]=(int)random(1,4.99);
  t[285]=t[285+tmp]=t[285+2*tmp]=(int)random(1,4.99);
  t[300]=t[300+tmp]=t[300+2*tmp]=(int)random(1,4.99);
  t[315]=t[315+tmp]=t[315+2*tmp]=(int)random(1,4.99);
  t[330]=t[330+tmp]=t[330+2*tmp]=(int)random(1,4.99);
  t[360]=t[360+tmp]=t[360+2*tmp]=(int)random(1,4.99);
  t[390]=t[390+tmp]=t[390+2*tmp]=(int)random(1,4.99);
  t[420]=t[420+tmp]=t[420+2*tmp]=(int)random(1,4.99);
  t[435]=t[435+tmp]=t[435+2*tmp]=(int)random(1,4.99);
  t[450]=t[450+tmp]=t[450+2*tmp]=(int)random(1,4.99);
  t[465]=t[465+tmp]=t[465+2*tmp]=(int)random(1,4.99);
  t[480]=t[480+tmp]=t[480+2*tmp]=(int)random(1,4.99);
  t[495]=t[495+tmp]=t[495+2*tmp]=(int)random(1,4.99);
  t[510]=t[510+tmp]=t[510+2*tmp]=(int)random(1,4.99);
  t[540]=t[540+tmp]=t[540+2*tmp]=(int)random(1,4.99);
  t[570]=t[570+tmp]=t[570+2*tmp]=(int)random(1,4.99);
  t[600]=t[600+tmp]=t[600+2*tmp]=(int)random(1,4.99);
  t[615]=t[615+tmp]=t[615+2*tmp]=(int)random(1,4.99);
  t[630]=t[630+tmp]=t[632+2*tmp]=(int)random(1,4.99);
  t[645]=t[645+tmp]=t[645+2*tmp]=(int)random(1,4.99);
  t[660]=t[660+tmp]=t[660+2*tmp]=(int)random(1,4.99);
  t[675]=t[675+tmp]=t[675+2*tmp]=(int)random(1,4.99);
  t[690]=t[690+tmp]=t[690+2*tmp]=(int)random(1,4.99);
  t[720]=t[720+tmp]=t[720+2*tmp]=(int)random(1,4.99);
  t[750]=t[750+tmp]=t[750+2*tmp]=(int)random(1,4.99);
  //2190 frame
  t[2220]=(int)random(1,4.99);//t[2220+tmp2]=(int)random(1,4.99);//
  t[2280]=(int)random(1,4.99);//t[2280+tmp2]=(int)random(1,4.99);
  t[2310]=(int)random(1,4.99);//t[2310+tmp2]=(int)random(1,4.99);
  t[2370]=(int)random(1,4.99);//t[2370+tmp2]=(int)random(1,4.99);
  t[2400]=(int)random(1,4.99);//t[2400+tmp2]=(int)random(1,4.99);
  t[2460]=(int)random(1,4.99);//t[2460+tmp2]=(int)random(1,4.99);
  t[2490]=(int)random(1,4.99);//t[2490+tmp2]=(int)random(1,4.99);
  t[2550]=(int)random(1,4.99);//t[2550+tmp2]=(int)random(1,4.99);
  t[2580]=(int)random(1,4.99);//t[2580+tmp2]=(int)random(1,4.99);
  t[2760]=(int)random(1,4.99);//t[2760+tmp2]=(int)random(1,4.99);
  t[2910]=(int)random(1,4.99);//t[2910+tmp2]=(int)random(1,4.99);
  t[2970]=(int)random(1,4.99);//t[2970+tmp2]=(int)random(1,4.99);
  t[2985]=(int)random(1,4.99);//t[2985+tmp2]=(int)random(1,4.99);
  t[3000]=(int)random(1,4.99);//t[3000+tmp2]=(int)random(1,4.99);
  t[3030]=(int)random(1,4.99);//t[2320+tmp2]=(int)random(1,4.99);
  t[3060]=(int)random(1,4.99);//t[2343+tmp2]=(int)random(1,4.99);
  t[3090]=(int)random(1,4.99);//t[2366+tmp2]=(int)random(1,4.99);
  t[3120]=(int)random(1,4.99);//t[2389+tmp2]=(int)random(1,4.99);
  t[3150]=(int)random(1,4.99);//t[2412+tmp2]=(int)random(1,4.99);
  t[3165]=(int)random(1,4.99);//t[2424+tmp2]=(int)random(1,4.99);
  t[3180]=(int)random(1,4.99);//t[2435+tmp2]=(int)random(1,4.99);
  t[3210]=(int)random(1,4.99);//t[2458+tmp2]=(int)random(1,4.99);
  t[3240]=(int)random(1,4.99);//t[2481+tmp2]=(int)random(1,4.99);
  t[3270]=(int)random(1,4.99);//t[2504+tmp2]=(int)random(1,4.99);
  t[3300]=(int)random(1,4.99);//t[2527+tmp2]=(int)random(1,4.99);
  /*t[3390]=t[2598+tmp2]=1;
  t[2604]=t[2604+tmp2]=4;
  t[3405]=t[2610+tmp2]=1;
  t[2616]=t[2616+tmp2]=4;
  t[3420]=t[2621+tmp2]=2;
  t[2627]=t[2627+tmp2]=3;
  t[3435]=t[2633+tmp2]=2;
  t[2639]=t[2639+tmp2]=3;
  t[2598+46]=t[2598+46+tmp2]=1;
  t[2604+46]=t[2604+46+tmp2]=3;
  t[2610+46]=t[2610+46+tmp2]=1;
  t[2616+46]=t[2616+46+tmp2]=3;
  t[2621+46]=t[2621+46+tmp2]=2;
  t[2627+46]=t[2627+46+tmp2]=4;
  t[2633+46]=t[2633+46+tmp2]=2;
  t[2639+46]=t[2639+46+tmp2]=4;
  t[2598+92]=t[2598+92+tmp2]=1;
  t[2604+92]=t[2604+92+tmp2]=2;
  t[2610+92]=t[2610+92+tmp2]=3;
  t[2616+92]=t[2616+92+tmp2]=4;
  t[2621+92]=t[2621+92+tmp2]=1;
  t[2627+92]=t[2627+92+tmp2]=2;
  t[2633+92]=t[2633+92+tmp2]=3;
  t[2639+92]=t[2639+92+tmp2]=4;
  t[2598+46+92]=t[2598+138+tmp2]=3;
  t[2604+46+92]=t[2604+138+tmp2]=4;
  t[2610+46+92]=t[2610+138+tmp2]=1;
  t[2616+46+92]=t[2616+138+tmp2]=2;
  t[2621+46+92]=t[2621+138+tmp2]=4;
  t[2627+46+92]=t[2627+138+tmp2]=3;
  t[2633+46+92]=t[2633+138+tmp2]=2;
  t[2639+46+92]=t[2639+138+tmp2]=1;
  t[2621+46+92+23]=t[2621+161+tmp2]=4;
  t[2627+46+92+23]=t[2627+161+tmp2]=3;
  t[2633+46+92+23]=t[2633+161+tmp2]=2;
  t[2639+46+92+23]=t[2639+161+tmp2]=1;
  //3892 frames
  /*
  int tmp3=384;
  t[4034]=t[4034+tmp3]=(int)random(1,4.99);t[4034+2*tmp3-1]=t[4034+3*tmp3-17]=(int)random(1,4.99);
  t[4058]=t[4058+tmp3]=(int)random(1,4.99);t[4058+2*tmp3-2]=t[4058+3*tmp3-18]=(int)random(1,4.99);
  t[4082]=t[4082+tmp3]=(int)random(1,4.99);t[4082+2*tmp3-2]=t[4082+3*tmp3-19]=(int)random(1,4.99);
  t[4106]=t[4106+tmp3]=(int)random(1,4.99);t[4106+2*tmp3-3]=t[4106+3*tmp3-20]=(int)random(1,4.99);
  t[4118]=t[4118+tmp3]=(int)random(1,4.99);t[4118+2*tmp3-4]=t[4118+3*tmp3-20]=(int)random(1,4.99);
  t[4130]=t[4130+tmp3]=(int)random(1,4.99);t[4130+2*tmp3-5]=t[4130+3*tmp3-21]=(int)random(1,4.99);
  t[4142]=t[4142+tmp3]=(int)random(1,4.99);t[4142+2*tmp3-5]=t[4142+3*tmp3-22]=(int)random(1,4.99);
  t[4154]=t[4154+tmp3]=(int)random(1,4.99);t[4154+2*tmp3-6]=t[4154+3*tmp3-22]=(int)random(1,4.99);
  t[4166]=t[4166+tmp3]=(int)random(1,4.99);t[4166+2*tmp3-7]=t[4166+3*tmp3-23]=(int)random(1,4.99);
  t[4178]=t[4178+tmp3]=(int)random(1,4.99);t[4178+2*tmp3-7]=t[4178+3*tmp3-24]=(int)random(1,4.99);
  t[4214]=t[4214+tmp3]=(int)random(1,4.99);t[4214+2*tmp3-8]=t[4214+3*tmp3-25]=(int)random(1,4.99);
  t[4238]=t[4238+tmp3]=(int)random(1,4.99);t[4238+2*tmp3-9]=t[4238+3*tmp3-25]=(int)random(1,4.99);
  t[4250]=t[4250+tmp3]=(int)random(1,4.99);t[4250+2*tmp3-10]=t[4250+3*tmp3-26]=(int)random(1,4.99);
  t[4262]=t[4262+tmp3]=(int)random(1,4.99);t[4262+2*tmp3-11]=t[4262+3*tmp3-27]=(int)random(1,4.99);
  t[4274]=t[4274+tmp3]=(int)random(1,4.99);t[4274+2*tmp3-11]=t[4274+3*tmp3-27]=(int)random(1,4.99);
  t[4286]=t[4292+tmp3]=(int)random(1,4.99);t[4286+2*tmp3-12]=t[4292+3*tmp3-28]=(int)random(1,4.99);
  t[4298]=(int)random(1,4.99);t[4298+2*tmp3-12]=(int)random(1,4.99);
  t[4310]=t[4310+tmp3]=(int)random(1,4.99);t[4310+2*tmp3-13]=t[4310+3*tmp3-29]=(int)random(1,4.99);
  t[4334]=t[4322+tmp3]=(int)random(1,4.99);t[4334+2*tmp3-14]=t[4322+3*tmp3-30]=(int)random(1,4.99);
  t[4346]=(int)random(1,4.99);t[4346+2*tmp3-15]=(int)random(1,4.99);
  t[4358]=(int)random(1,4.99);t[4358+2*tmp3-16]=(int)random(1,4.99);
  t[4370]=(int)random(1,4.99);t[4370+2*tmp3-16]=(int)random(1,4.99);
  // 7070 frames -> 6530
  int tmp5=275,tmp6=-540;
  t[7093+tmp6]=t[7093+tmp5+tmp6]=t[7116+tmp6]=t[7116+tmp5+tmp6]=t[7139+tmp6]=t[7139+tmp5+tmp6]=(int)random(1,4.99);
  t[7162+tmp6]=t[7162+tmp5+tmp6]=t[7185+tmp6]=t[7185+tmp5+tmp6]=t[7208+tmp6]=t[7208+tmp5+tmp6]=(int)random(1,4.99);
  t[7231+tmp6]=t[7231+tmp5+tmp6]=t[7254+tmp6]=t[7254+tmp5+tmp6]=t[7277+tmp6]=t[7277+tmp5+tmp6]=(int)random(1,4.99);
  t[7300+tmp6]=t[7300+tmp5+tmp6]=t[7323+tmp6]=t[7323+tmp5+tmp6]=t[7346+tmp6]=t[7346+tmp5+tmp6]=(int)random(1,4.99);
  //7081 frames
  t[7104-12]=(int)random(1,4.99);
  t[7173-12]=(int)random(1,4.99);
  t[7196-12]=(int)random(1,4.99);
  t[7219-12]=(int)random(1,4.99);
  t[7242-12]=(int)random(1,4.99);
  t[7311-12]=(int)random(1,4.99);
  t[7334-12]=(int)random(1,4.99);
  t[7357-12]=(int)random(1,4.99);
  t[7379-12]=(int)random(1,4.99);
  t[7448-12]=(int)random(1,4.99);
  t[7471-12]=(int)random(1,4.99);
  t[7494-12]=(int)random(1,4.99);
  t[7517-12]=(int)random(1,4.99);
  t[7586-12]=(int)random(1,4.99);
  t[7609-12]=(int)random(1,4.99);
  t[7632-12]=(int)random(1,4.99);*/
}
int frame=0,score=0,combo=0,multi=1,keyboard=0;
float note=0,noteco=0;
void draw(){
  if(combo<10)multi=1;
  else if(combo<25)multi=2;
  else if(combo<50)multi=4;
  else multi=8;
  textSize(30);
  fill(0);
  rect(0,0,1000,1000);
  stroke(127);
  fill(0);
  rect(850,550,50,385);
  frame++;
  for(int i=1;i<122;i++){
    fill((int)r[i],(int)g[i],(int)b[i]);
    stroke((int)r[i],(int)g[i],(int)b[i]);
    ellipse(x[i],y[i],R,R);
    x[i]+=vx[i];
    y[i]+=vy[i];
    if(x[i]<=0||x[i]>=1000){
      vx[i]=-vx[i];
    }
    if(y[i]<=0||y[i]>=1000){
      vy[i]=-vy[i];
    }
  }
  for(int i=1;i<122;i++){
    for(int j=i+1;j<122;j++){
      if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=R*R){
        float tmp11=vx[i],tmp12=vy[i];
        vx[i]=vx[j];
        vy[i]=vy[j];
        vx[j]=tmp11;
        vy[j]=tmp12;
      }
    }
  }
  fill(127);
  if(note==0){
    text("100.000",800,100);
    text("%",935,100);
  }
  else{
    textAlign(RIGHT);
    text(100*noteco/note,930,100);
    textAlign(LEFT);
    text("%",935,100);
  }
  if(frame>=50){
    noStroke();
    for(int i=frame;i>frame-50;i--){
      if(t[(int)i]==1){
        float tme=(float)frame-(float)i;
        float dist=tme*15.0+0.1*tme*tme;
        float size=120+dist/125;
        fill(255);
        triangle(350-(dist-size)/10,dist-size,425-(dist-size)/20,dist-size,350-dist/10,dist);
        triangle(425-(dist-size)/20,dist-size,350-dist/10,dist,425-dist/20,dist);
        triangle(350-(dist-size)/10,dist-size,425-dist/20,dist,425-(dist-size)/20,dist-size);
        triangle(350-(dist-size)/10,dist-size,425-dist/20,dist,350-dist/10,dist);
      }
      if(t[(int)i]==2){
        float tme=(float)frame-(float)i;
        float dist=tme*15.0+0.1*tme*tme;
        float size=120+dist/125;
        fill(255);
        triangle(425-(dist-size)/20,dist-size,500,dist,500,dist-size);
        triangle(425-(dist-size)/20,dist-size,500,dist,425-dist/20,dist);
        triangle(500,dist-size,425-dist/20,dist,425-(dist-size)/20,dist-size);
        triangle(500,dist-size,425-dist/20,dist,500,dist);
      }
      if(t[(int)i]==3){
        float tme=(float)frame-(float)i;
        float dist=tme*15.0+0.1*tme*tme;
        float size=120+dist/125;
        fill(255);
        triangle(500,dist-size,575+dist/20,dist,500,dist);
        triangle(500,dist-size,575+dist/20,dist,575+(dist-size)/20,dist-size);
        triangle(500,dist,575+(dist-size)/20,dist-size,500,dist-size);
        triangle(500,dist,575+(dist-size)/20,dist-size,575+dist/20,dist);
      }
      if(t[(int)i]==4){
        float tme=(float)frame-(float)i;
        float dist=tme*15.0+0.1*tme*tme;
        float size=120+dist/125;
        fill(255);
        triangle(575+(dist-size)/20,dist-size,650+dist/10,dist,575+dist/20,dist);
        triangle(575+(dist-size)/20,dist-size,650+dist/10,dist,650+(dist-size)/10,dist-size);
        triangle(575+dist/20,dist,650+(dist-size)/10,dist-size,575+(dist-size)/20,dist-size);
        triangle(575+dist/20,dist,650+(dist-size)/10,dist-size,650+dist/10,dist);
      }
    }
    if(t[frame-50]!=0){
      combo=0;
      note++;
    }
  }
  if(key>='a'&&key<='z')keyboard=key-'a'+'A';else keyboard=key;
  noStroke();
  if(keyboard=='F'&&keyPressed&&frame>=50){
    fill(0);
    triangle(270,800,385,800,250,1000);
    triangle(385,800,250,1000,375,1000);
    for(int i=(int)frame-42;i>(int)frame-50;i--){
      if(t[i]==1){
        t[i]=0;
        score+=(50*(frame-42-i)+100)*multi;
        combo++;
        note+=multi;
        noteco+=multi;
      }
    }
  }
  else{
    fill(127);
    triangle(270,800,385,800,250,1000);
    triangle(385,800,250,1000,375,1000);
    triangle(275,800,375,1000,250,1000);
    triangle(275,800,375,1000,385,800);
  }
  if(keyboard=='G'&&keyPressed&&frame>=50){
    fill(0);
    triangle(385,800,500,800,375,1000);
    triangle(500,800,375,1000,500,1000);
    for(int i=(int)frame-42;i>(int)frame-50;i--){
      if(t[i]==2){
        t[i]=0;
        score+=(50*(frame-42-i)+100)*multi;
        combo++;
        note+=multi;
        noteco+=multi;
      }
    }
  }
  else{
    fill(127);
    triangle(385,800,500,800,375,1000);
    triangle(500,800,375,1000,500,1000);
    triangle(385,800,500,1000,500,800);
    triangle(385,800,500,1000,375,1000);
  }
  if(keyboard=='H'&&keyPressed&&frame>=50){
    fill(0);
    triangle(500,800,615,800,500,1000);
    triangle(500,800,625,1000,500,1000);
    for(int i=(int)frame-42;i>(int)frame-50;i--){
      if(t[i]==3){
        t[i]=0;
        score+=(50*(frame-42-i)+100)*multi;
        combo++;
        note+=multi;
        noteco+=multi;
      }
    }
  }
  else{
    fill(127);
    triangle(500,800,615,800,500,1000);
    triangle(500,800,625,1000,500,1000);
    triangle(615,800,625,1000,500,800);
    triangle(615,800,625,1000,500,1000);
  }
  if(keyboard=='J'&&keyPressed&&frame>=50){
    fill(0);
    triangle(615,800,750,1000,730,800);
    triangle(615,800,750,1000,625,1000);
    for(int i=(int)frame-42;i>(int)frame-50;i--){
      if(t[i]==4){
        t[i]=0;
        score+=(50*(frame-42-i)+100)*multi;
        combo++;
        note+=multi;
        noteco+=multi;
      }
    }
  }
  else{
    fill(127);
    triangle(615,800,750,1000,730,800);
    triangle(615,800,750,1000,625,1000);
    triangle(730,800,625,1000,615,800);
    triangle(730,800,625,1000,750,1000);
  }
  stroke(255);
  line(350,0,250,1000);
  line(425,0,375,1000);
  line(500,0,500,1000);
  line(575,0,625,1000);
  line(650,0,750,1000);
  line(270,800,730,800);
  textSize(50);
  fill(127,0,127);
  text("F",290,900);
  text("G",415,900);
  text("H",545,900);
  text("J",665,900);
  textSize(30);
  fill(255);
  text("SCORE",70,100);
  textAlign(CENTER);
  text(score,120,150);
  textAlign(LEFT);
  text("COMBO",70,500);
  textAlign(CENTER);
  text(combo,120,550);
  textAlign(LEFT);
  textSize(100);
  if(noteco/note>0.9||note==0){
    fill(255,127,127);
    text("S",850,250);
  }
  else if(noteco/note>0.8){
    fill(51,255,51);
    text("A",850,250);
  }
  else if(noteco/note>0.7){
    fill(255,255,51);
    text("B",850,250);
  }
  else if(noteco/note>0.6){
    fill(51,51,255);
    text("C",850,250);
  }
  else if(noteco/note>0.5){
    fill(150,75,0);
    text("D",850,250);
  }
  else{
    fill(127);
    text("F",850,250);
  }
  textSize(50);
  if(multi==2){
    fill(51,51,255);
    text("X2",90,650);
  }
  else if(multi==4){
    fill(102,255,102);
    text("X4",90,650);
  }
  else if(multi==8){
    fill(255,255,102);
    text("X8",90,650);
  }
  stroke(127);
  fill(255);
  if(frame<7700){
    rect(850,935-(frame/20),50,frame/20);
  }
  else{
    rect(850,550,50,385);
  }
}
