#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const maxS = 1e5 + 1;

int dp[maxS][N] = {}, arr[N];
int n; 

bool dequy(int s, int x){
	if (s == 0) return true;
	if (s < 0 || x <= 0) return false;
	if (dp[s][x] != 0) return dp[s][x] - 1;

	bool ans = dequy(s - arr[x], x - 1) | dequy(s, x - 1);

	dp[s][x] = ans + 1;
	return ans;
}

int main(){
	cin >> n;

	int sum = 0;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];	
	} 

	int dem = 0; vector<int> sums;
	for (int i = 1; i <= sum; i++){
		if (dequy(i, n)){
			dem++;
			sums.push_back(i);
		}
	}

	cout << dem << endl;
	for (auto i: sums) cout << i << " ";
	return 0;
}