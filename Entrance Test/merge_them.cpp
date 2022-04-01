#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void mergeInterval(int s1, int e1, int s2, int e2, int s, int e, vector<int> &input){
	vector<int> temp;
	while(s1 <= e1 && s2 <= e2){
		if(input[s1] < input[s2]){
			temp.push_back(input[s1]);
			s1++;
		}
		else{
			temp.push_back(input[s2]);
			s2++;
		}
	}
	while(s1 <= e1){
		temp.push_back(input[s1]);
		s1++;
	}
	while(s2 <= e2){
		temp.push_back(input[s2]);
		s2++;
	}
	int c = 0;
	int max_v = INT_MIN, min_v = INT_MAX;
	for(int i=s; i<=e; i++){
		input[i] = temp[c];
		max_v = max(max_v, temp[c]);
		min_v = min(min_v, temp[c]);
		c++;
	}
	temp.clear();
	ans += max_v - min_v;
}

void merge(int start, int end, vector<int> &input){
	int mid = start + (end - start)/2;
	if(start < end){
		merge(start, mid, input);
		merge(mid+1, end, input);
		mergeInterval(start, mid, mid + 1, end, start, end, input);
	}
}

void solve(std::vector<int> &input){
	merge(0, input.size()-1, input);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> input;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	solve(input);
	cout << ans << endl;
	return 0;
}