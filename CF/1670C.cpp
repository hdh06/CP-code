#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int link[N];
int sz[N];
bool z[N];

int find(int x){
	if (x != find[x]) return find[x] = find(find[x]);
	return x;
}

bool join(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return false;

	link[a] = b;
	sz[b] += a;
	z[a] |= z[b];
	return true;
}

void solve(){
	int n; cin >> n;
	int a[N], b[N], d[N];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> d[i];

	int pa[N], pb[N], vis[N] = {};
	for (int i = 1; i <= n; i++){
		vis[d[i]] = true;
		pa[a[i]] = i;
		pb[b[i]] = i;
	}

	for (int i = 1; i <= n; i++) link[i] = i, sz[i] = 1, z[i] = 0;

	for (int i = 1; i <= n; i++){
		if (d[i] == 1) z[find(d[i])] = 1;
		
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}