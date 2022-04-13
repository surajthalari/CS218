#include <bits/stdc++.h>

using namespace std;

bool divide(vector<int> &volumes, int k, int mid){
    int count = 0;
    int sum = 0;
    int n = volumes.size();
    for (int i = 0; i < n; i++) {
        if (volumes[i] > mid)
            return false;
        sum += volumes[i];
        if (sum > mid) {
            count++;
            sum = volumes[i];
        }
    }
    count++;
    if (count <= k)
        return true;
    return false;
}

int solve(std::vector<int> &volumes, int k){

    int sum = 0;
    int max_v = INT_MIN;
    for(int i=0;i<volumes.size();i++) {
        sum += volumes[i];
        max_v = max(max_v, volumes[i]);
    }


    if(k == 1) return sum;

    int low = max_v, high = sum;
    int mid = low + (high - low) / 2;

    while(low < high){
        mid = low + (high - low) / 2;
        if(divide(volumes, k, mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> volumes;
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        volumes.push_back(temp);
    }

    cout << solve(volumes, k) << endl;
    return 0;
}