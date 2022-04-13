#include <bits/stdc++.h>

using namespace std;


int solve(std::vector<int> &candies, int n){
    priority_queue<int,vector<int>,greater<int> > pq(candies.begin(), candies.end());
    int ans = 0;
    if(n == 0 || n == 1) return ans;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a+b)*2;
        pq.push(a+b);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> candies;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        candies.push_back(temp);
    }

    cout << solve(candies, n) << endl;
    return 0;
}