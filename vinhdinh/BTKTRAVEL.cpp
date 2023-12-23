#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 17;

ll c[N][N] = {};

bool vis[N] = {};
int n;

ll dequy(int i){
	ll ans = LLONG_MAX;
	for (int j = 1; j <= n; j++) if (!vis[j]){
		vis[j] = true;
		ans = min(ans, dequy(j) + c[i][j]);
		vis[j] = false;
	}

	if (ans == LLONG_MAX) return 0;
	return ans;
}

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> c[i][j];
	vis[6] = 1;
	cout << dequy(6);
	return 0;
}
    