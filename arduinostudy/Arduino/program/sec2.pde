void check1()//max1 min1 결정
{dclear();song.play();  //잔잔해지는 노래를 튼다.
 parseFile3();
 int data=0;float maxHe=0,minHe=200,maxHu=0,minHu=200,maxT=0,minT=200; //max min값을 구하기 위해 절대 도달하지 못하는 값을 미리 넣어둔다. data는 data 개수를 나타낸다.
 float datax=50;//T  // 초기 값을 결정해준다(아무 의미도 없다)
 float datay=50;//He
 float dataz=50;//Hu;
 println("checking..."); //console 창에 아무 이상없이 체크중이라고 표시해준다.
 int cnt=0;
 while(true){
   if(data>800){break;} //데이터 개수가 4000개가 넘으면 반복문을 나가게 한다.
   else{
     datax=data1[cnt];cnt++;
     datay=data1[cnt];cnt++;
     dataz=data1[cnt];cnt++;
     if(datax>maxT){maxT=datax;}if(datax<minT){minT=datax;}           // maxmin 값에 변동이 있으면 바꿔서 넣는다
     if(datay>maxHe){maxHe=datay;}if(datay<minHe){minHe=datay;}
     if(dataz>maxHu){maxHu=dataz;}if(dataz<minHu){minHu=dataz;}      
     dpush(datax,datay,dataz,255,0,0);                            // 점을 그래프에 나타내도록 stack에 넣는다.
     show();                                                          // 점의 추가 현황을 그래프에 나타내도록 해준다.
     data++;}}
  maHe=maxHe;miHe=minHe;maHu=maxHu;miHu=minHu;maT=maxT;miT=minT;   //최종값을 전역변수에 넣는다.
  max1="T/He/Hu: "+Float.toString(maxT)+" "+Float.toString(maxHe)+" "+Float.toString(maxHu);  //화면에 표시할 수 있도록 문자열을 변화시킨다.
  min1="T/He/Hu: "+Float.toString(minT)+" "+Float.toString(minHe)+" "+Float.toString(minHu);  
  Cuboid((maT+miT)/2,(maHe+miHe)/2,(maHu+miHu)/2,(maT-miT)/2,(maHe-miHe)/2,(maHu-miHu)/2,0,255,0,0,1);
  println("finished");song.pause();}  //끝났다고 표시하고 노래를 멈춘다.
void check2()//max2 min2 결정
{dclear();song.play();
parseFile4();
  int data=0;float maxHe=0,minHe=200,maxHu=0,minHu=200,maxT=0,minT=200,error=0; //max min값을 구하기 위해 절대 도달하지 못하는 값을 미리 넣어둔다. data는 data 개수를 나타낸다.
  float datax=50;//T  // 초기 값을 결정해준다(아무 의미도 없다)
  float datay=50;//He
  float dataz=50;//Hu;
  println("checking..."); //console 창에 아무 이상없이 체크중이라고 표시해준다.
  int cnt=0;
  while(true){
   if(data>800){break;} //데이터 개수가 4000개가 넘으면 반복문을 나가게 한다.
   else{
     datax=data1[cnt];cnt++;
     datay=data1[cnt];cnt++;
     dataz=data1[cnt];cnt++;
     if(datax>maxT){maxT=datax;}if(datax<minT){minT=datax;}          // maxmin 값에 변동이 있으면 바꿔서 넣는다
     if(datay>maxHe){maxHe=datay;}if(datay<minHe){minHe=datay;}
     if(dataz>maxHu){maxHu=dataz;}if(dataz<minHu){minHu=dataz;}
     if(datax<miT || datax>maT || datay<miHe || datay>maHe || dataz<miHu || dataz>maHu){  // 점을 그래프에 나타내도록 stack에 넣는다. (범위를 넘어갔으므로 빨간색 점을 표시하도록 해준다)
       dpush(datax,datay,dataz,255,0,0);
       error=1;}
     else{dpush(datax,datay,dataz,255,255,255);}  // 점을 그래프에 나타내도록 stack에 넣는다.
     show();                                      // 점의 추가 현황을 그래프에 나타내도록 해준다.
     data++;}}
   maHe=maxHe;miHe=minHe;maHu=maxHu;miHu=minHu;maT=maxT;miT=minT;   //최종값을 전역변수에 넣는다.
   max2="T/He/Hu: "+Float.toString(maxT)+" "+Float.toString(maxHe)+" "+Float.toString(maxHu);  //화면에 표시할 수 있도록 문자열을 변화시킨다.
   min2="T/He/Hu: "+Float.toString(minT)+" "+Float.toString(minHe)+" "+Float.toString(minHu);
  if(error==1){println("error"); // 거짓말이라고 표시하고 충격을 가한다.
  //충격
  }
  else
  {println("safe");}  //거짓말이 아니라고 표시해준다.
   println("finished");
   song.pause();}  //끝났다고 표시하고 노래를 멈춘다.
