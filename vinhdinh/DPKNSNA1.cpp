#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 501;
int const M = 1e6 + 1;

ll dp[M] = {};
int w, v;
int n, m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;	

	for (int i = 1; i <= n; i++){
		cin >> v >> w;
		for (int j = m; j >= 0; j--) if (j - w >= 0){
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << *max_element(dp, dp + m + 1);
	return 0;
}