import java.util.Queue;
import java.util.ArrayDeque;
Queue<Integer> queue = new ArrayDeque<Integer>();
void bfs(int start){
  fill(0);stroke(0);text("bfs",50,50);
  if(oneloop==0){  //노드 연결 다 넣기
    for(int i=0;i<lineend;i++){
    adj.get(lin[i].n1).add(lin[i].n2);
    adj.get(lin[i].n2).add(lin[i].n1);
    }
    oneloop=1;
  }
  
  queue.add(start);
  while(queue.size()>0){
    int temp=queue.peek();
    queue.remove();
    
    if(visit[temp]){continue;}
     visit[temp]=true;
     println(temp);
     
    int k=adj.get(temp).size();
    for(int i=0;i<k;i++){   //for
      queue.add(adj.get(temp).get(i));
    }
  }
}
