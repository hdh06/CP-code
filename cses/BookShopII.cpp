#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 101;
int const X = 1e5 + 1;

int main(){
	int n, x;
	cin >> n >> x;

	int h[N], s[N], k[N];
	for (int i = 1; i <= n; i++) cin >> h[i];	
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> k[i];

	vector<ii> d;

	for (int i = 1; i <= n; i++){
		int p = 1;
		while (k[i] - p > 0){
			d.push_back({h[i]*p, s[i]*p});
			k[i] -= p;
			p <<= 1;
		}
		if (k[i] > 0) d.push_back({h[i]*k[i], s[i]*k[i]});
	}

	int dp[X] = {};

	for (auto e: d){
		int w = e[0], v = e[1];
		for (int j = x; j >= w; j--)
			dp[j] = max(dp[j], dp[j - w] + v);
	}

	cout << *max_element(dp, dp + x + 1);
	return 0;
}