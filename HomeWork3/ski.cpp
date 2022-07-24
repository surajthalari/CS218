#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> A;

int recursion(int i, int j, int r, int c) {
    int ans=0; 
    if(i < 0 || i >= r || j < 0 || j >= c) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(j+1 < c && A[i][j]>A[i][j+1]) ans=max(ans, 1+ recursion(i, j+1, r, c));
    if(j-1 >= 0 && A[i][j]>A[i][j-1]) ans=max(ans, 1+ recursion(i, j-1, r, c));
    if(i+1 < r && A[i][j]>A[i+1][j]) ans=max(ans, 1+ recursion(i+1, j, r, c));
    if(i-1 >= 0 && A[i][j]>A[i-1][j]) ans=max(ans, 1+ recursion(i-1, j, r, c));
    return dp[i][j] = ans;
}



int solve(int r, int c){
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans = max(ans,recursion(i, j, r, c));
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans + 1;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int r, c;
    cin >> r >> c;
    vector<int> temp;
    vector<int> tempDP;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int a;
            cin >> a;
            temp.push_back(a);
            tempDP.push_back(-1);
        }
        A.push_back(temp);
        dp.push_back(tempDP);
        temp.clear();
        tempDP.clear();
    }


    
    cout << solve(r, c) << endl;
    A.clear();
    dp.clear();

    return 0;
}