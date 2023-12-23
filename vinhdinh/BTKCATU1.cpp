#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 26;
ll const INF = LLONG_MIN;

int n; ll m;
ll v[N], w[N];

ll dequy(int n, ll m){
	if (n == 0) return 0ll;
	return max(dequy(n - 1, m), (m - w[n] >= 0?dequy(n - 1, m - w[n]) + v[n]:0ll));
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	cout << max(0ll, dequy(n, m));
	return 0;
}