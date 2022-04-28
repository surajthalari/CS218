#include <bits/stdc++.h>

using namespace std;

unordered_map<int, char> cl;


int solve(vector<pair<int, int>> &assignments){

    sort(assignments.begin(), assignments.end(), [](pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    });

    map<int, vector<int>> m;
    unordered_map<int, int> cmap; 
    set<int> trackDeadlines;

    for(int i=0;i<assignments.size();i++){
        trackDeadlines.insert(assignments[i].second);
    }


    // Denotes the deadline before which you cant insert any task
    int currentMaxFill = 0;

    cout << endl;

    for(int i=0;i<assignments.size();i++){
        if(assignments[i].second > currentMaxFill){
            m[assignments[i].second].push_back(assignments[i].first);
            cmap[assignments[i].second]++;
            for(auto j=trackDeadlines.begin();j!=trackDeadlines.end();j++){
                if(*j > assignments[i].second && m[*j].size() != 0){
                    cmap[*j]++;
                }
            }
            if(cmap[assignments[i].second] == assignments[i].second){
                currentMaxFill = assignments[i].second;
            }
        }
    }



    int ans = 0;
    

    cout << "####Assignments Order######" << endl;

    for(auto it = m.begin(); it != m.end(); it++){
        for(int i=0;i<it->second.size();i++){
            cout << cl[it->second[i]] << " ";
            ans += it->second[i];
        }
    }
    cout << endl;
    cout << "###########################" << endl;

    return ans;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int hw;
    cin >> hw;
    vector<pair<int, int>> assignments;
    int c = 65;
    for(int i=0;i<hw;i++){
        int a, b;
        cin >> a >> b;
        assignments.push_back(make_pair(a, b));
        cl[a] = c;
        c++;
    }

    int ans = solve(assignments);

    cout << "Optimal Solution ----> " << ans << " points" << endl; 

    return 0;
}