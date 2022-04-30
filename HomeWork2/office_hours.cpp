#include <bits/stdc++.h>

using namespace std;


int solve(vector<pair<int, int>> &intervals){
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    sort(intervals.begin(), intervals.end());

    for(int i=0;i<intervals.size();i++){
        pair<int, int> temp = intervals[i];

        if(temp.second != INT_MAX){
            pq.push({temp.second, temp.first});
        }
        else{
            while(!pq.empty()){
                pair<int, int> t = pq.top();
                // cout << t.second << " " << t.first << endl;
                pq.pop();
                if(t.second <= temp.first && temp.first <= t.first){
                    ans++;
                    break;
                }
            }
        }
    }
    // cout << "###############################" << endl;
    // while(!pq.empty()){
    //     pair<int, int> t = pq.top();
    //     pq.pop();
    //     cout << t.second << " " << t.first << endl;
    // }


    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> intervals;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        intervals.push_back(make_pair(a, INT_MAX));
    }

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        intervals.push_back(make_pair(a, b));
    }

    cout << solve(intervals) << endl;

    return 0;
}