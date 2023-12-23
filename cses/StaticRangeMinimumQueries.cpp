#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 22;

int log2(int x){
	int ans = 0;
	while (x > 0){
		x >>= 1;
		if (x > 0) ans ++;
	}
	return ans;
}

int main(){
	int n, q; cin >> n >> q;
	int minq[N][L] = {};

	for (int i = 1; i <= n; i++){
		cin >> minq[i][0];
	}

	for (int x = 1; x < L; x++){
		for (int i = 1; i <= n; i++){
			minq[i][x] = min(minq[i][x - 1], minq[min(i + (1 << (x - 1)), n)][x - 1]);
		}
	}

	while (q--){
		int a, b; cin >> a >> b;
		int k = log2(b - a + 1);
		// cout << k << " ";
		cout << min(minq[a][k], minq[b - (1 << k) + 1][k]) << endl;
	}
	return 0;
}