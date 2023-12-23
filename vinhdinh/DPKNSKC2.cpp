#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1001;
int const M = 11112;

ll dp[M] = {};
ll arr[N], v[N] = {}, p[M] = {};

int main(){
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> v[i] >> arr[i];

	dp[0] = 0;
	ll maxn = 0, maxp = 0;
	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n; i++) if (j - arr[i] >= 0){
			if (dp[j] < dp[j - arr[i]] + v[i]){
				dp[j] = dp[j - arr[i]] + v[i];
				p[j] = i;
			}
		}
		if (maxn < dp[j]){
			maxn = dp[j];
			maxp = j;
		}
	}

	cout << dp[maxp] << endl;

	ll fre[N] = {};
	while (maxp > 0){
		fre[p[maxp]]++;
		maxp -= arr[p[maxp]];
	}

	for (int i = 1; i <= n; i++) cout << fre[i] << " ";
	return 0;
}