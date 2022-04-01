#include <bits/stdc++.h>

using namespace std;

bool checkInGrpah(int i, int j, int n){
	return i >= 0 && i < n && i >= 0 && j < n;
}


int solve(int n, int t, vector<string> &grid){
	vector<vector<int>> graph(n, vector<int> (n, 0));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == 'b') graph[i][j] = t + 1;
			else graph[i][j] = 1;
		}
	}


	vector<vector<int>> dij(n, vector<int> (n, INT_MAX));

	dij[0][0] = graph[0][0];

	set<pair<int, pair<int, int>>> s;

	s.insert(make_pair(0, make_pair(0, 0)));

	int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

	while(!s.empty()){
		pair<int, pair<int, int>> temp = *s.begin();
		s.erase(s.begin());

		for(int i=0;i<4;i++){
			int curr_x = temp.second.first + dx[i];
			int curr_y = temp.second.second + dy[i];

			if(!checkInGrpah(curr_x, curr_y, n)) continue;

			if(dij[curr_x][curr_y] > dij[temp.second.first][temp.second.second] + graph[curr_x][curr_y]){
				if(dij[curr_x][curr_y] != INT_MAX){
					s.erase(s.find(make_pair(dij[curr_x][curr_y], make_pair(curr_x, curr_y))));
				}
				dij[curr_x][curr_y] = dij[temp.second.first][temp.second.second] + graph[curr_x][curr_y];
				s.insert(make_pair(dij[curr_x][curr_y], make_pair(curr_x, curr_y)));
			}
		}
	}

	return dij[n-1][n-1] - 1;

}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<string> g;
	int n, t;
	cin >> n >> t;
	for(int i=0;i<n;i++){
		string temp;
		cin >> temp;	
		g.push_back(temp);
	}

	cout << solve(n, t, g) << endl;
	return 0;
}