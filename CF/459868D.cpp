#include <bits/stdc++.h>

using namespace std;

int const N = 1000;
int const M = 16;

int n, m;
bool vis[1 << M] = {};
	
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		int x = 0;
		for (int i = 0; i < m; i++){
			x = 2 * x + s[i] - '0';
		}
		vis[x] = 1;
	}
	
	int pre = 0;
	int ans = 0;
	for (int i = 0; i < (1 << m); i++){
		int z = i ^ (i >> 1);
		if (vis[z]){
			ans += __builtin_popcount(pre ^ z);
			pre = z;
		}
	}
	
	cout << ans;
	return 0;
}