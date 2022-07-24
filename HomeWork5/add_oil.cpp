#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;

    cin >> n >> m;

    map<int, vector<pair<int, int>>> al;
	unordered_map<int, bool> visited;
	vector<int> vall;
	int ans = 0;

	for(int i=0;i<n;i++){
		visited[i] = false;
	}

	for(int i=0;i<m;i++){
		int x, y, z;
		cin >> x >> y >> z;
		al[x].push_back({y, z});
		al[y].push_back({x, z});
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

	pq.push({0, {0, 0}});
	while(!pq.empty()){
		if(vall.size() == n){
			break;
		}
		pair<int, pair<int, int>> temp = pq.top();
		pq.pop();
		ans = max(ans, temp.second.second);
		if(visited[temp.second.first]){
			continue;
		}
		vall.push_back(temp.second.first);
		visited[temp.second.first] = true;
		for(int i=0;i<al[temp.second.first].size();i++){
			if(!visited[al[temp.second.first][i].first]){
				pq.push({al[temp.second.first][i].second, {al[temp.second.first][i].first, al[temp.second.first][i].second}});
			}
		}
	}


	cout << ans << endl;
    return 0;
}