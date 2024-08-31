

String[] file;
int nodes = 0;
int w = 10;
int h = 10;
int startNode;
Solver graph;
ArrayList<Edge> shortestPath;


void setup(){
  
  //!!!SPECIFY GRAPH FILE NAME HERE!!!
  file = loadStrings("graph.txt");
  
  //!!SPECIFY START NODE HERE!!!
  startNode = 1;
  
  size(800,800); 
  smooth();
  
  //initialize global data structures
  graph = new Solver(int(file[0]));
 
  
  shortestPath = new ArrayList<Edge>();
  
  for(int i = 1; i<file.length; i++){
    String[] Edge = split(file[i], ' ');
    graph.addEdge(new Edge(int(Edge[0]),int(Edge[1]),int(Edge[2])));
  }
  graph.outputGraph();
  long start, end, total;
  start = System.currentTimeMillis();
  println("Solving...");
  graph.solve(startNode);
  end = System.currentTimeMillis();
  total = end - start;
  OutputShortestPath();
  println("Solver took: " + total + " msec to solve the graph."); 
}


void draw(){
 background(255);
 fill(230);
 for(int i = 0; i< shortestPath.size(); i++){
   Edge aEdge = shortestPath.get(i);
   if(i==0) aEdge.c = color(200,0,0);
   float x1, y1, x2, y2;
   x1 = aEdge.pos.x;
   y1 = aEdge.pos.y;
   x2 = aEdge.pos.x;
   y2 = aEdge.pos.y;
   //draw a line from this start Edge to the end Edge.
   //get start node coordinates
   for(int j=0; j<shortestPath.size(); j++){
     Edge bEdge = shortestPath.get(j);
     if(aEdge.end == bEdge.start){
       x2 = bEdge.pos.x;
       y2 = bEdge.pos.y;
     }
     //fill(0);
     //text(nf(bEdge.m_PathLength,0,0),((x1+x2)/2),((y1 + y2)/2));
     stroke(0,0,200);
     line(x1,y1,x2,y2); 
   }
   
   
   aEdge.drawEdge();
   
   
   fill(0);
   text(nf(aEdge.distFromStart,0,0), x1, y1 + 33);
   //draw the path length 
 } 
   
}

//output textual representation of shortest path.
void OutputShortestPath(){
  println("Node \t Distance");
  for(int i = 0; i< shortestPath.size(); i++){
    Edge aEdge = (Edge)shortestPath.get(i);
    println(aEdge.end + "\t" + aEdge.distFromStart);
  }
}
