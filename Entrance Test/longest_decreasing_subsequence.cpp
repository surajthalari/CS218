#include <bits/stdc++.h>

using namespace std;



int solve(std::vector<int> &input){
	vector<int> lds(input.size(), 1);
	for(int i = 1; i<input.size();i++){
		for(int j = 0;j<i;j++){
			if(input[j] > input[i] && 1 + lds[j] > lds[i]){
				lds[i] = 1 + lds[j];
			}
		}
	}

	return *max_element(lds.begin(), lds.end());
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

	cout << solve(input) << endl;
	return 0;
}