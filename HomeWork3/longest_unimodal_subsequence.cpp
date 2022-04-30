#include <bits/stdc++.h>

using namespace std;



int solve(int n, vector<int> &arr){
    int dp[n][2];
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i] > arr[j]){
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
        }
    }

    int ans = 1;
    for(int i=0;i<n;i++){
        ans = max(ans, dp[i][0] + dp[i][1] - 1);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    cout << solve(n, arr) << endl;

    return 0;
}