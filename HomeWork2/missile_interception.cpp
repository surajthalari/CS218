#include <bits/stdc++.h>

using namespace std;
struct point {
    int x;
    int y;
    int dis1;
    int dis2;
};

int distance(struct point a, struct point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compare(struct point a, struct point b) {
    return a.dis1 > b.dis1;
}

int solve(vector<point> &a){
    sort(a.begin() , a.end() ,compare);
    int n = a.size();
    int mindis = a[0].dis1;
    int maxdis2 = -1;
    if (n == 1) {
        return min(a[0].dis2, mindis);
    }
    for (int i = 1; i < n; i++) {
        maxdis2 = max(a[i - 1].dis2, maxdis2);
        mindis = min(mindis, maxdis2 + a[i].dis1);
    }
    maxdis2 = max(a[n-1].dis2, maxdis2);
    mindis = min(mindis, maxdis2);
    return mindis;
}

int main() {
    struct point p1, p2;
    vector<point> a;
    int x, y, n;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> n;
    for (int i = 0; i < n; i++) {
        struct point temp;
        cin >> x >> y;
        temp.x = x;
        temp.y = y;
        temp.dis1 = distance(p1, temp);
        temp.dis2 = distance(p2, temp);
        a.push_back(temp);
    }
    
    cout << solve(a) << endl;

    return 0;
}