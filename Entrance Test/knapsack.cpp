#include <bits/stdc++.h>

using namespace std;



int solve(int W, int n, vector<int> &w, vector<int> &v){
	vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(w[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i-1]]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][W];
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> w,v;
	int n, W;
	cin >> W >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		w.push_back(a);
		v.push_back(b);
	}

	cout << solve(W, n, w, v) << endl;
	return 0;
}