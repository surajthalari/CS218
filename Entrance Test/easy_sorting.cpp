#include <bits/stdc++.h>

using namespace std;

int solve(std::vector<int> &input){
	int one_c=0, two_c=0, three_c=0;

	for(int i = 0; i < input.size(); i++){
		if(input[i] == 3){
			three_c++;
		}
		else if(input[i] == 1){
			one_c++;
		}
		else{
			two_c++;
		}
	}

	int tw_o = 0, th_o = 0, o_tw = 0, th_tw = 0, o_th = 0, tw_th = 0;

	for(int i=0;i<input.size();i++){
		if(i < one_c){
			if(input[i] == 2) tw_o++;
			else if(input[i] == 3) th_o++;
		}
		else if(i < one_c + two_c){
			if(input[i] == 1) o_tw++;
			else if(input[i] == 3) th_tw++;
		}
		else{
			if(input[i] == 1) o_th++;
			else if(input[i] == 2) tw_th++;
		}
	}

	int ans = 0;

	int temp = min(tw_o, o_tw);
	ans += temp;
	tw_o -= temp;
	o_tw -= temp;

	temp = min(th_o, o_th);
	ans += temp;
	th_o -= temp;
	o_th -= temp;

	temp = min(th_tw, tw_th);
	ans += temp;
	th_tw -= temp;
	tw_th -= temp;

	ans += max(tw_o, max(th_o, max(o_tw, max(th_tw, max(o_th, tw_th))))) * 2;

	return ans;

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