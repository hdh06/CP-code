#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int g[N];

void solve(){
	int n, m; cin >> n >> m;	
	for (int i = 1; i <= n; i++) g[i] = 0;
	while (m--){
		int x; cin >> x;
		g[x]++;
	}

	sort(g + 1, g + n + 1);

	int ans = 0;

	int a = 0, b = 0;

	for (int i = 1; i <= n; i++){

	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}