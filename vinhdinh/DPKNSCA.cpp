#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int const maxM = 20001;

int main(){
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;

		int arr[N];

		for (int i = 1; i <= n; i++) cin >> arr[i];

		bool dp[N][maxM] = {};

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) dp[i][0] = 1;
		for (int i = 1; i <= maxM; i++){
			for (int j = 1; j <= n; j++){
				dp[j][i] = dp[j - 1][i] | (i - arr[j] >= 0?dp[j - 1][i - arr[j]]:0);
			}
		}

		for (int i = 0; i <= maxM; i++)
			if (dp[n][i]) cout << i << " ";
		cout << endl;
	}
	return 0;
}