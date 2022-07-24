#include <bits/stdc++.h>

using namespace std;





int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    unordered_map<char, int> c;

    for(int i=0;i<k;i++){
        int a;
        cin >> a;
        c[97 + i] = a;
    }

    string s;

    cin >> s;

    for(int p=0;p<n;p++){
        int i=0,j=p+1;
        while(i<n && j<n){
            dp[i][j] = INT_MAX;
            if(s[i] == s[j]){
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
            else{
                dp[i][j] = min(dp[i][j], min(dp[i][j-1] + c[s[j]], dp[i+1][j] + c[s[i]]));
            }
            i++;
            j++;
        }

    }

    cout << dp[0][n-1] << endl;
    return 0;
}