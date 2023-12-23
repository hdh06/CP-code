#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int main(){
	int n, k; cin >> n >> k;
	bool vis[N] = {};
	for (int i = 1; i <= k; i++){
		int x; cin >> x;
		vis[x] = 1;
	}
	int pre[N] = {}, suf[N + 1] = {};
	
	for (int i = 1; i <= n; i++)
		pre[i] = vis[i] ? pre[i - 1] + 1: 0;
	for (int i = n; i >= 1; i--)
		suf[i] = vis[i] ? suf[i + 1] + 1: 0;
		
	int ans = 0;
	for (int i = 1; i <= n; i++) if (!vis[i]){
		if (vis[0]) ans = max(ans, pre[i - 1] + suf[i + 1] + 1);
		else ans = max(ans, pre[i - 1]);
	}
	cout << ans;
	return 0;
}