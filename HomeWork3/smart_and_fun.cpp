#include <bits/stdc++.h>

using namespace std;




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    });


    for(int i=0;i<n;i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    int ts = 0, tn = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        ts += arr[i].first;
        tn += arr[i].second;
        if(ts < 0 || tn < 0){
            break;
        }
        ans += ts + tn;
    }

    cout << ans << endl;

    return 0;
}