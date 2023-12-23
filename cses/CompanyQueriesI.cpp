#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 20;

int par[N] = {}, up[N][L] = {}, n, q;

void pre_binary_lifting(){
	for (int i = 1; i <= n; i++) up[i][0] = par[i];
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];
}

int ancestor(int x, int k){
	for (int j = 0; (1 << j) <= k; j++){
		if (k >> j & 1) x = up[x][j];
	}
	return x;
}

int main(){
	cin >> n >> q;

	for (int i = 2; i <= n; i++){
		cin >> par[i];
		up[i][0] = par[i];
	}

	pre_binary_lifting();

	// cout << up[4][0] << " " << par[4];

	while(q--){
		int x, k;
		cin >> x >> k;
		int ans = ancestor(x, k);
		cout << (ans == 0?-1:ans) << endl;
	}
	return 0;
}	