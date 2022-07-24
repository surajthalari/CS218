#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <cmath>
#include <bits/stdc++.h>
 
using namespace std;
#define NIL 0
#define INF INT_MAX
 
 
class BipGraph
{
	int m, n;
 
	list<int> *adj;
 
	int *pairU, *pairV, *dist;
 
public:
	BipGraph(int m, int n); 
	void addEdge(int u, int v); 
 
	bool bfs();
 
	bool dfs(int u);
 
	int solve();
};
 
 
int BipGraph::solve()
{
	pairU = new int[m+1];
	pairV = new int[n+1];
	dist = new int[m+1];
	for (int u=0; u<=m; u++)
		pairU[u] = NIL;
	for (int v=0; v<=n; v++)
		pairV[v] = NIL;
	int result = 0;
	while (bfs())
	{
		for (int u=1; u<=m; u++)
			if (pairU[u]==NIL && dfs(u))
				result++;
	}
	return result;
}
 
bool BipGraph::bfs()
{
	queue<int> Q;
 
	for (int u=1; u<=m; u++)
	{
		if (pairU[u]==NIL)
		{
			dist[u] = 0;
			Q.push(u);
		}
		else dist[u] = INF;
	}
 
	dist[NIL] = INF;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (dist[u] < dist[NIL])
		{
			list<int>::iterator i;
			for (i=adj[u].begin(); i!=adj[u].end(); ++i)
			{
				int v = *i;
				if (dist[pairV[v]] == INF)
				{
					dist[pairV[v]] = dist[u] + 1;
					Q.push(pairV[v]);
				}
			}
		}
	}
	return (dist[NIL] != INF);
}
 
bool BipGraph::dfs(int u)
{
	if (u != NIL)
	{
		list<int>::iterator i;
		for (i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			int v = *i;
			if (dist[pairV[v]] == dist[u]+1)
			{
				if (dfs(pairV[v]) == true)
				{
					pairV[v] = u;
					pairU[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}
 
BipGraph::BipGraph(int m, int n)
{
	this->m = m;
	this->n = n;
	adj = new list<int>[m+1];
}
 
void BipGraph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}
 
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}
 
int main()
{
    int p,q,b;
    int ax, by, cz;
    cin>>p>>q>>b;
    struct student
    {
        int x, y, z;
    };
    vector<student> st;
    vector<pair<int, int>> sh;
    
    for(int i = 1; i <= p; i++) {
        cin>>ax>>by>>cz;
        st.push_back({ax, by, cz});
    }
    for(int i = 1; i <= q; i++) {
        cin>>ax>>by;
        sh.push_back(make_pair(ax, by));
    }
	BipGraph g(p, q);
    for(int i = 1; i <= st.size(); i++) {
        for (int j = 1; j <= sh.size(); j++) {
            if((distance(st[i].x,st[i].y,sh[j].first,sh[j].second)/st[i].z) <= (float)b) {
                g.addEdge(i, j);
            }
        }
    }
 
 
	cout << p-g.solve();
 
	return 0;
}