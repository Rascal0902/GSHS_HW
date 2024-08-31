import java.util.Comparator;
import java.util.PriorityQueue;
public class MyComparator implements Comparator<PVector>{
  public int compare (PVector s1, PVector s2){
    return (s1.x < s2.x)? 1 : 0;  // 작은걸 올린다.
  }
}
PriorityQueue<PVector> pq = new PriorityQueue<PVector>(new MyComparator());
Vector<Vector<PVector>> adj2 = new Vector<Vector<PVector>>(10);
float[] distance = new float[10];
void dijkstra(int start){
  fill(0);stroke(0);text("dijkstra",50,50);
  if(oneloop==0){  //노드 연결 다 넣기
    for(int i=0;i<lineend;i++){
      adj2.get(lin[i].n1).add(new PVector(lin[i].weight,lin[i].n2));
      adj2.get(lin[i].n2).add(new PVector(lin[i].weight,lin[i].n1));
    }
    for(int i=0;i<10;i++){
      distance[i]=1000000000;
    }
    oneloop=1;
  }
  
  pq.add(new PVector(0,start));
  while(pq.size()>0){
    PVector temp=pq.peek();
    pq.remove();
    
    if(distance[(int)temp.y]<=temp.x){continue;}
     distance[(int)temp.y]=temp.x;
     //println(temp);
     
    int k=adj2.get((int)temp.y).size();
    for(int i=0;i<k;i++){   //for
      pq.add(new PVector(adj2.get((int)temp.y).get(i).x+temp.x,adj2.get((int)temp.y).get(i).y));
    }
  }
}
