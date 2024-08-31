import java.util.Vector;
ArrayList<Integer> stack = new ArrayList<Integer>();
boolean[] visit = new boolean[10];
Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>(10);
int oneloop=0;
int time=0;

void dfs1(int start){
  fill(0);stroke(0);text("dfs",50,50);
  if(oneloop==0){  //노드 연결 다 넣기
    for(int i=0;i<lineend;i++){
    adj.get(lin[i].n1).add(lin[i].n2);
    adj.get(lin[i].n2).add(lin[i].n1);
    }
    oneloop=1;
  }
  
  if(visit[start]){return;} // visit 처리
   node[start].visit=true;
   visit[start]=true;
   while(true){if(time>2000000000){break;}time++;}time=0;
   println(start);
   fill(0,0,255);stroke(0,0,255);ellipse(node[start].x,node[start].y,50,50);
   textSize(30);stroke(255);fill(255); text((int)node[start].n,node[start].x,node[start].y+10);
   while(true){if(time>2000000000){break;}time++;}time=0;
  int k=adj.get(start).size();
  for(int i=0;i<k;i++){   //for
    dfs1(adj.get(start).get(i));
  }
  
}

void dfs2(int start){
  fill(0);stroke(0);text("dfs",50,50);
  if(oneloop==0){  //노드 연결 다 넣기
    for(int i=0;i<lineend;i++){
    adj.get(lin[i].n1).add(lin[i].n2);
    adj.get(lin[i].n2).add(lin[i].n1);
    }
    oneloop=1;
  }
  stack.add(start);
  while(stack.size()>0){
    int temp=stack.get(stack.size()-1);
   
    stack.remove(stack.size()-1);
    
    if(visit[temp]){continue;}
     visit[temp]=true;
     
    int k=adj.get(temp).size();
    for(int i=0;i<k;i++){   //for
      stack.add(adj.get(temp).get(i));
    }
  }
}
