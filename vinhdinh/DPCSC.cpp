#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int const maxD = 51;

int main(){
	int n;
	cin >> n;

	int arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N][maxD] = {};


	int maxn = 0;
	for (int i = 1; i <= n; i++){
		for (int d = 1; d < maxD; d++){
			dp[i][d] = 1;
			for (int j = i - 1; j >= 1; j --){
				if (arr[i] - arr[j] == d){
					dp[i][d] = max(dp[i][d], dp[j][d] + 1);
				}
			}
			maxn = max(maxn, dp[i][d]);
		}
	}	

	cout << maxn;

	return 0;
}