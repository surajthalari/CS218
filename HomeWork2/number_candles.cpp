#include <bits/stdc++.h>

using namespace std;

int getNextV(int dollars, vector<pair<int, int>> &temp, vector<int> &candles){
    if(dollars < temp[0].first) return -1;
    int t = dollars%temp[0].first;
    if(t == 0) return temp[0].second;
    t += temp[0].first;
    for(int i=8;i>=0;i--){
        if(candles[i] <= t){
            return i+1;
        }
    }
    return temp[0].second;
}


void solve(int dollars, vector<int> &candles){
    vector<int> ans;
    vector<pair<int, int>> temp;


    for(int i=8;i>=0;i--) temp.push_back({candles[i], i+1});

    sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    while(dollars){
        int t = getNextV(dollars, temp, candles);
        if(t == -1) break;
        dollars -= candles[t-1];
        ans.push_back(t);
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int dollars;
    cin >> dollars;
    vector<int> candles(10, 0);
    for(int i=0;i<9;i++){
        cin >> candles[i];
    }
    solve(dollars, candles);
    return 0;
}