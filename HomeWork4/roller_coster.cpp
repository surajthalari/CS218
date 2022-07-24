#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> h;
    for(int i=0;i<n;i++){
    	int a;
    	cin >> a;
    	h.push_back(a);
    }

    if (n == 0){
    	cout << 0 << endl;
    }
    else{
    	pair<int, int> minv, maxv;
    	minv = {h[0], 0};
    	maxv = {h[0], 0};
    	int i=0;
    	int l=1;
    	while(i<n){
    		if(h[i] - maxv.first > k || h[i] - maxv.first < -k){
    			i = maxv.second + 1;
            	maxv = {h[i], i};
            	minv = {h[i], i};
            	l = 1;
            	ans = max(ans, l);
            	continue;
    		}
    		if(h[i] - minv.first > k || h[i] - minv.first < -k){
    			i = minv.second + 1;
            	maxv = {h[i], i};
            	minv = {h[i], i};
            	l = 1;
            	ans = max(ans, l);
            	continue;
    		}
    		maxv = max(maxv, {h[i], i});
        	minv = min(minv, {h[i], i});

        	ans = max(ans, l);
        	l = l + 1;
        	i = i + 1;
    	}
    }
    cout << ans << endl;

    return 0;
}