#include <bits/stdc++.h>
#define NIL -1
using namespace std;

 
class Graph
{
    int V; 
    list<int> *adj;
    vector<vector<int>> temp;
 
    void SCCUtil(int u, int disc[], int low[],
                stack<int> *st, bool stackMember[]);
public:
    Graph(int V); 
    void addEdge(int v, int w); 
    vector<vector<int>> SCC(); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
                    bool stackMember[])
{
    
    static int time = 0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;
 
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i; 
        if (disc[v] == -1)
        {
            SCCUtil(v, disc, low, st, stackMember);
 
            low[u] = min(low[u], low[v]);
        }
 
        
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
 
    int w = 0; 
    if (low[u] == disc[u])
    {
        vector<int> t;
        while (st->top() != u)
        {
            w = (int) st->top();
            t.push_back(w+1);
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st->top();
        t.push_back(w+1);
        temp.push_back(t);
        stackMember[w] = false;
        st->pop();
    }
}
 
vector<vector<int>> Graph::SCC()
{
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();
 
    for (int i = 0; i < V; i++)
    {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }
 
    
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember);

    return this->temp;
}
 
int main()
{

    int n, m;
    cin >> n >> m;

    Graph g(n);

    map<int, vector<int>> t_graph;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        t_graph[a+1].push_back(b+1);
        g.addEdge(a-1, b-1);
    }

    vector<vector<int>> ans = g.SCC();
    
    for(int i=0;i<ans.size();i++){
        sort(ans[i].begin(), ans[i].end());
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            int node = ans[i][j];
        }
    }

    return 0;
}