/*
 * Jonghwa Park
 * suakii@gmail.com
*/
red_blood_cell[] red = new red_blood_cell[100000]; int redcnt=0;
white_blood_cell[] white = new white_blood_cell[100000]; int whitecnt=0;
virus[] bad = new virus[1000000]; int viruscnt=0;
O2[] oxy = new O2[1000000]; int O2cnt=30;
float checkred=0,checkwhite=0,checkvirus=0,checkO2=0;
class World {
  
  void born(float x, float y) {
       float ran=random(4);PVector l = new PVector(x,y);
       if(ran>=1){ red[redcnt]=new red_blood_cell(l);redcnt++;}
       else{white[whitecnt]=new white_blood_cell(l);whitecnt++;}
  }
  
  void virus_born(float x,float y){bad[viruscnt]=new virus(new PVector(x,y));viruscnt++;}
  
  void oxy_born(float x,float y){oxy[O2cnt]=new O2(new PVector(x,y));O2cnt++;}
  
  void run() {
    float k=0.01;
    
    // set red velocity
    for(int i=0;i<redcnt;i++){if(red[i].health<0){continue;}
      red[i].velocity.x = map(noise(red[i].xoff),0,1,-red[i].maxspeed,red[i].maxspeed);red[i].velocity.y = map(noise(red[i].yoff),0,1,-red[i].maxspeed,red[i].maxspeed);}
      
    // set white velocity
    for(int i=0;i<whitecnt;i++){if(white[i].health<0){continue;}
      white[i].velocity.x = map(noise(white[i].xoff),0,1,-white[i].maxspeed,white[i].maxspeed);white[i].velocity.y = map(noise(white[i].yoff),0,1,-white[i].maxspeed,white[i].maxspeed);}
      
      
    float min=10000;int take=0;
    // set virus velocity
    for(int i=0;i<viruscnt;i++){if(bad[i].health<=0){continue;}min=10000;take=0;
      bad[i].velocity= map.vec(bad[i].location.x,bad[i].location.y).mult(noise(bad[i].xoff));
      
      for(int j=0;j<whitecnt;j++){if(white[j].health<=0){continue;}
        float dist=(new PVector(white[j].location.x-bad[i].location.x,white[j].location.y-bad[i].location.y)).mag();
        // distance virus - white < 50  -> virus died
        if(dist<50){bad[i].health=0;map.died(bad[i].location.x,bad[i].location.y);            }
        
        else{if(dist<min){min=dist;take=j;}}}  // 가장 가까이에 있는 백혈구 저장
      // virus accerlation// 가장 가까운 백혈구 존재하면 멀어지는 방향으로 힘
      if(take!=0){bad[i].accleration= (new PVector(-white[take].location.x+bad[i].location.x,-white[take].location.y+bad[i].location.y)).mult(k);}  // 가장 가까운 백혈구 존재하면 멀어지는 방향으로 힘
    }
    
    for(int i=0;i<whitecnt;i++){if(white[i].health<=0){continue;}
      min=10000;take=0;
      for(int j=0;j<viruscnt;j++){if(bad[j].health<=0){continue;}
        float dist=(new PVector(white[i].location.x-bad[j].location.x,white[i].location.y-bad[j].location.y)).mag();
        
        if(dist<min){min=dist;take=j;}}  // 가장 가까이에 있는 바이러스 저장
      //set white accleration// 가장 가까운 바이러스 존재하면 가까워지는 방향으로 힘
      if(take!=0){white[i].accleration= (new PVector(-bad[take].location.x+white[i].location.x,-bad[take].location.y+white[i].location.y)).mult(k);} 
    }
    
    for(int i=0;i<O2cnt;i++){if(oxy[i].health<=0){continue;}
      min=10000;take=0;
      //set oxy velocity
      oxy[i].velocity.x = map(noise(oxy[i].xoff),0,1,-oxy[i].maxspeed,oxy[i].maxspeed);oxy[i].velocity.y = map(noise(oxy[i].yoff),0,1,-oxy[i].maxspeed,oxy[i].maxspeed);
      
      for(int j=0;j<redcnt;j++){if(red[j].health<=0){continue;}
        float dist=(new PVector(red[j].location.x-oxy[i].location.x,red[j].location.y-oxy[i].location.y)).mag();
        
        if(dist<50){red[j].health+=20;oxy[i].health=0;oxy[i].check();} // 적혈구와 산소랑 만나면 적혈구의 수명 증가
        else{if(dist<min){min=dist;take=j;}}}
    }
    
    
    for(int i=0;i<redcnt;i++){if(red[i].health<=0){continue;}
      min=10000;take=0;
      
      for(int j=0;j<O2cnt;j++){if(oxy[j].health<=0){continue;}
        float dist=(new PVector(red[i].location.x-oxy[j].location.x,red[i].location.y-oxy[j].location.y)).mag();
        if(dist<min){min=dist;take=j;}}
        
      if(take!=0){red[i].accleration= (new PVector(-oxy[take].location.x+red[i].location.x,-oxy[take].location.y+red[i].location.y)).mult(k);} // 적혈구가 산소 발견하면 산소 따라가기
    }
    display();
  }
  void display(){
    checkred=0;checkwhite=0;checkvirus=0;checkO2=0;
    map.update();if(window==2){map.display();}
    for(int i=0;i<redcnt;i++){if(red[i].health<=0){continue;}
      checkred++;red[i].update();red[i].borders();
      if(window==0 || window==1){red[i].display(red[i].vir);}
    }
    for(int i=0;i<whitecnt;i++){if(white[i].health<=0){continue;}
      checkwhite++;white[i].update();white[i].borders();
      if(window==0){white[i].display(white[i].vir);}
    }
    for(int i=0;i<viruscnt;i++){if(bad[i].health<=0){continue;}
      checkvirus++;bad[i].update();bad[i].borders();
      if(window==0 || window==2){bad[i].display(bad[i].vir);}
    }
    for(int i=0;i<O2cnt;i++){if(oxy[i].health<=0){continue;}
      checkO2++;oxy[i].update();oxy[i].borders();
      if(window==1){oxy[i].display(oxy[i].vir);}
    }
  }
}
