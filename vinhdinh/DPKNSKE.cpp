#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int const S = 50000 + 1;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int arr[N]; int sum = 0;
		for (int i = 1; i <= n; i++){
		 	cin >> arr[i];
		 	sum += arr[i];
		}

		bool dp[N][S] = {};

		for (int i = 1; i <= n; i++){
			dp[i][0] = 1;
		}

		for (int s = 1; s <= sum; s++){
			for (int i = 1; i <= n; i++) if (s - arr[i] >= 0){
				dp[i][s] = dp[i - 1][s] | dp[i - 1][s - arr[i]];
			}
			else dp[i][s] = dp[i - 1][s];
		}	

		int minn = INT_MAX;

		for (int s = 1; s <= sum; s++) if (dp[n][s]){
			minn = min(minn, abs(sum - 2*s));
			// cout << s << " " << dp[n][s] << endl;
		}

		cout << minn << endl;
	}
	return 0;
}