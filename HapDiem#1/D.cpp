#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int main(){
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;

	int curr = -1, c[N] = {}, f[N] = {};
	for (int i = n - 1, z = m - 1; i >= 0 && z >= 0; i--){
		if (b[z] == a[i]){
			if (curr != -1) f[z] = max(f[z + 1], curr - i);
			curr = c[z] = i;	
			z--;	
		}
	}	

	int d[N] = {}, g[N] = {}; curr = -1;
	for (int i = 0, z = 0; i < n && z < m; i++){
		if (b[z] == a[i]){
			if (curr != -1) g[z] = max(g[z - 1], curr - i);
			curr = d[z] = i;	
			z++;	
		}
	}	

	int ans = 0;
	for (int i = 0; i < m - 1; i++){
		ans = max({ans, f[i + 1], g[i], c[i + 1] - d[i]});
	}
	cout << ans;
	return 0;
}