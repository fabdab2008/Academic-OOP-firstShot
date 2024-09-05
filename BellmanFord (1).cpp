// Bellman Ford algorithm in C++
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct edge //contains the ending vertex and the weight of an edge
{
    char v;
    int w;
};
struct node
{
    char vertex;
    int d;
    node *parent;
    vector<edge> adj; //adjacent vertices with weight
};
class Graph
{
public:
    int V; // number of vertices/nodes in graph
    node *nodes; //vertices of the graph
    Graph(int v)
    {
        V=v;
        nodes = new node[V];
        for (int i = 0; i < V; i++) ////A, B, C, D, E....
        {
            nodes[i].vertex='A'+i;
        }
    }
    void AddWeightedEdge(char u, char n, int w)
    {
        edge e;
        e.v=n;
        e.w=w;
        for(int i=0; i<V; i++)
        {
            if(nodes[i].vertex==u)
                nodes[i].adj.push_back(e);
        }
    }
    void printPath(node *s)
    {
        if(s->parent != NULL)
        {
            this->printPath(s->parent);
            cout << " ----> ";
        }
        cout << s->vertex <<" ";
    }
    void INITIALIZE_SINGLE_SOURCE(char s) //vertex is represented using character
    {
        for(int i=0; i<V; i++)
        {
            nodes[i].parent=NULL;
            nodes[i].d = 999999;
            if(nodes[i].vertex==s)
                nodes[i].d = 0;
        }
    }
    int relax(char u, char v, int w)
    {
        node *U,*V;
        int changed=0;
        for(int i=0; i<this->V; i++)
        {
            if(nodes[i].vertex==u)
            {
                U = &nodes[i];
            }
            if(nodes[i].vertex==v)
                V = &nodes[i];
        }
        if(V->d > U->d + w)
        {
            V->d = U->d + w;
            V->parent = U;
            changed=1;
        }
        return changed;
    }
};
bool BELLMAN_FORD(Graph G, char s)
{
    G.INITIALIZE_SINGLE_SOURCE(s);
    for(int i=1; i<=G.V-1; i++)
    {
        for(int j=0; j < G.V; j++)
        {
            for(int k=0; k < G.nodes[j].adj.size(); k++)
            {
                G.relax(G.nodes[j].vertex, G.nodes[j].adj[k].v,G.nodes[j].adj[k].w);
            }
        }
    }
    for(int j=0; j<G.V; j++) //all edge in graph from adjacency list
    {
        for(int k=0; k<G.nodes[j].adj.size(); k++) // "
        {
            if(G.relax(G.nodes[j].vertex, G.nodes[j].adj[k].v,G.nodes[j].adj[k].w))
                return false;
        }
    }
    return true;
}
int main()
{
    Graph G(5); // 5 is the number of vertices in the graph
    for(int i=0; i<5; i++)
    {
        cout<<G.nodes[i].vertex<<endl;
    }
    G.AddWeightedEdge('A','B',3);
    G.AddWeightedEdge('A','C',1);
    G.AddWeightedEdge('B','D',1);
    G.AddWeightedEdge('B','E',2);
    G.AddWeightedEdge('C','B',1);
    G.AddWeightedEdge('C','D',4);
    G.AddWeightedEdge('D','E',3);
//    G.AddWeightedEdge('D','C',-10);
    if(BELLMAN_FORD(G,'A'))
    {
        for(int  i=0; i<G.V; i++)
        {
            cout<<"\nShortest Path from A to "<<G.nodes[i].vertex<<endl;
            G.printPath(&G.nodes[i]);
        }
    }
    else
    {
         cout<< "Negative Weighted cycle present. No solution!!"<<endl;
    }
}



