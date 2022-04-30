#include <bits/stdc++.h>

using namespace std;



int solve(int t, vector<pair<pair<int, int>, int>> &cheepChomp){
    sort(cheepChomp.begin(), cheepChomp.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
        if(a.first.first == b.first.first) return a.first.second < b.first.second;
        return a.first.first < b.first.first;
    });

    // cout << "-----------------------------" << endl;

    // for(int i=0;i<cheepChomp.size();i++){
    //     cout << cheepChomp[i].first.first << " " << cheepChomp[i].first.second << " " << cheepChomp[i].second << endl;
    // }

    // cout << "-----------------------------" << endl;

    stack<pair<pair<int, int>, int>> s;

    for(int i=0;i<cheepChomp.size();i++){
        if(s.empty()){
            s.push(cheepChomp[i]);
        }
        else{
            pair<pair<int, int>, int> temp = s.top();
            if(max(temp.first.first, cheepChomp[i].first.first) <= min(temp.first.second, cheepChomp[i].first.second)){
                s.pop();
                if(temp.second == cheepChomp[i].second){
                    s.push({{min(temp.first.first, cheepChomp[i].first.first), max(temp.first.second, cheepChomp[i].first.second)}, temp.second});
                }
                else if(temp.first.second > cheepChomp[i].first.second){
                    if(temp.second > cheepChomp[i].second){
                        s.push(temp);
                    }
                    else{
                        s.push({{temp.first.first, cheepChomp[i].first.first - 1}, temp.second});
                        s.push(cheepChomp[i]);
                        s.push({{cheepChomp[i].first.second + 1, temp.first.second}, temp.second});
                    }
                }
                else{
                    if(temp.second < cheepChomp[i].second){
                        s.push({{temp.first.first, cheepChomp[i].first.first - 1}, temp.second});
                        s.push(cheepChomp[i]);
                    }
                    else{
                        s.push({{temp.first.first, temp.first.second}, temp.second});
                        s.push({{temp.first.second + 1, cheepChomp[i].first.second}, cheepChomp[i].second});
                    }
                }
            }
            else{
                s.push(cheepChomp[i]);
            }
        }
    }

    int ans = 0;
    while(!s.empty()){
        pair<pair<int, int>, int> temp = s.top();
        s.pop();
        if(temp.first.first <= temp.first.second){
            if(temp.second == 0){
                ans += (temp.first.second - temp.first.first + 1);
            }
            else{
                ans += (temp.first.second - temp.first.first + 1)*3;
            }
        }
    }

    return ans;

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t, m, n, a, b, c;
    cin >> t >> m >> n;
    vector<pair<pair<int, int>, int>> cheepChomp;
    for(int i=0;i<m+n;i++){
        cin >> a >> b >> c;
        cheepChomp.push_back({{a, b}, c});
    }

    cout << solve(t, cheepChomp) << endl;

    return 0;
}