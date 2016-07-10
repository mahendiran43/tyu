# tyu
#include <iostream>
#include <list>
class Graph
{
    int V;    
    list<int> *adj;   
public:
    Graph(int V) 
  { 
this->V = V;
 adj = new list<int>[V];
 }
    ~Graph()  
     { 
delete [] adj; 
}
    void addEdge(int v, int w);
    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); 
}
void Graph::greedyColoring()
{
    int result[V];
    result[0]  = 0;
    for (int u = 1; u < V; u++)
        result[u] = -1;  
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
    for (int u = 1; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
        result[u] = cr;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}
int main()
{
    Graph a(5);
    a.addEdge(0, 1);
    a.addEdge(0, 2);
    a.addEdge(1, 2);
    a.addEdge(1, 3);
    a.addEdge(2, 3);
    a.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    a.greedyColoring();

    Graph b(5);
    b.addEdge(0, 1);
    b.addEdge(0, 2);
    b.addEdge(1, 2);
    b.addEdge(1, 4);
    b.addEdge(2, 4);
    b.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    b.greedyColoring();

    return 0;
}
