#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1001;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, r;
		cin >> n >> r;

		ll h[N];

		for (int i = 1; i <= n; i++){
			cin >> h[i];
		}

		int dp[N] = {};

		int maxn = 0;
		for (int i = 1; i <= n; i++){
			dp[i] = 1;
			for (int j = i - 1; j >= 1; j--) if (h[j] > h[i] || j == r){
				dp[i] = max(dp[i], dp[j] + 1);
			}
			maxn = max(maxn, dp[i]);
		}
		cout << maxn << endl;
	}	
	return 0;
}

//|-| |) |-|
