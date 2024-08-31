
class Solver {
  int nodeCount;
  ArrayList<Edge> graph;
  ArrayList<Edge> possibleNodes;
  
  
  
  Solver(int nc) {
    nodeCount = nc;
    graph = new ArrayList<Edge>();
    possibleNodes = new ArrayList<Edge>();
  }
  
  void addEdge(Edge edge) {
    graph.add(edge);
  }
  
  void outputGraph() {
    println("Nodes: " + nodeCount);
    println("Graph");
    
    for (Edge edge : graph)
      edge.printEdge();
  }
  
  void solve(int start) {
    
    //to do
    
  }
  
  
  Edge closestAvailableEdge() {
    
    Edge shortest = null;
    int shortDist = 32767;
    int removalIndex = 0;
    
   int i = 0;
   for (Edge edge : possibleNodes) {
      if (edge.distFromStart < shortDist && edge.open == true) {
        shortest = edge;
        shortDist = shortest.distFromStart;
        removalIndex = i;
        i++;
      }
    }
    if (shortest != null) {
      shortest.open = false;
      possibleNodes.remove(removalIndex);
    }
    return shortest;
    
  }
  
  
  ArrayList getPossibleNodes(int node, int distFromStart) {
  
    ArrayList<Edge> possibles = new ArrayList<Edge>();
    for (Edge edge : graph) {
      if (edge.start == node && edge.open == true) {
        edge.distFromStart = distFromStart + edge.len;
        possibles.add(edge);
      }
    }
    return possibles;
    
  }
  
  void closeNode(int node) {
    for (Edge edge : graph) {
      if(edge.end == node) {
        edge.open = false;
      }
    }
  }
  
  
  
  
}
