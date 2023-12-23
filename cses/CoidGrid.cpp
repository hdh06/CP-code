#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int n;

vector<int> g[N * 2], rg[N * 2];

int vis[2 * N], t = 0, mt[2 * N];

bool kuhn(int v){
	if (vis[v] == t) return false;
	vis[v] = t;
	for (auto u: g[v]) if (mt[u] == -1 || kuhn(mt[u])){
		mt[u] = v;
		return true;
	}
	return false;
}

bool isGet[2 * N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++){
		char c; cin >> c;
		if (c == 'o') g[i].push_back(j + n), rg[j + n].push_back(i);
	}
	
	memset(mt, -1, sizeof mt);
	
	int ans = 0;
	for (int i = 1; i <= n; i++){
		t++;
		ans += kuhn(i);
	}
	
	cout << ans << "\n";
	for (int i = n + 1; i <= 2 * n; i++) if (mt[i] != -1){
		int a = 0, b = 0;
		for (auto j: g[mt[i]]) if (!isGet[j]) a++;
		for (auto j: rg[i]) if (!isGet[j]) b++;
		if (a > b){
			cout << 1 << " " << mt[i] << "\n";		
			for (auto j: g[mt[i]]) isGet[j] = 1;
			isGet[mt[i]] = 1;
		}else{ 
			cout << 2 << " " << i - n << "\n";
			for (auto j: rg[i]) isGet[j] = 1;
			isGet[i] = 1;
		}
	}
	return 0;
}