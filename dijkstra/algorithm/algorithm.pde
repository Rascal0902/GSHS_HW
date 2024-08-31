Node[] node = new Node[10];
Line[] lin = new Line[10000];
float lineend=0;
void setup(){
  size(1000,500);
  background(255);strokeWeight(5);
  textSize(30);textAlign(CENTER);
  for(int i=0;i<10;i++){
    adj.add(new Vector<Integer>());
    adj2.add(new Vector<PVector>());
  }
  node[0]= new Node(100,100,0);
  node[1]= new Node(200,100,1);
  node[2]= new Node(100,200,2);
  node[3]= new Node(300,100,3);
  node[4]= new Node(200,200,4);
  node[5]= new Node(100,300,5);
  node[6]= new Node(400,100,6);
  node[7]= new Node(200,300,7);
  node[8]= new Node(300,200,8);
  node[9]= new Node(100,400,9);
  lin[0]= new Line(0,1,5);lineend++;
  lin[1]= new Line(0,2,3);lineend++;
  lin[2]= new Line(1,4,4);lineend++;
  lin[3]= new Line(2,4,7);lineend++;
  lin[4]= new Line(2,5,2);lineend++;
  lin[5]= new Line(5,9,5);lineend++;
  lin[6]= new Line(5,7,6);lineend++;
  lin[7]= new Line(4,7,10);lineend++;
  lin[8]= new Line(4,8,1);lineend++;
  lin[9]= new Line(3,8,3);lineend++;
  lin[10]= new Line(3,6,8);lineend++;
  update();
  //bfs(0);
  //dijkstra(0);
  //dfs2(0);
  frameRate(5);
}
void draw(){
  //dfs1(0);
}
void update(){
  background(255);
  for(int i=0;i<lineend;i++){
    lin[i].display();
  }
  for(int i=0;i<10;i++){
    node[i].display();
  }
}
