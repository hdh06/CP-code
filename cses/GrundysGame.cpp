#include <bits/stdc++.h>
#include <debug.h>

using namespace std;

int main(){
	int dp[10000] = {0, 0};
	int maxx = 0;
	for (int i = 3; i < 10000; i++){
		vector<int> vi;
		for (int j = 1; j < (i + 1) / 2; j++){
			vi.push_back(dp[j] ^ dp[i - j]);
		}
		sort(vi.begin(), vi.end());
		int mex = 0;
		for (int i = 0; i < vi.size(); i++)
			if (vi[i] == mex) mex++;
		dp[i] = mex;
		if (mex == 1) maxx = i;
		// debug(i, vi);
	}	
	cerr << maxx;
	return 0;
}