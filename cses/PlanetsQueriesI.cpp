#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const L = 31;

int p[N][L] = {};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i][0];
	
	for (int i = 1; i < L; i++)
		for (int j = 1; j <= n; j++)
			p[j][i] = p[p[j][i - 1]][i - 1];

	while (q--){
		int x, k; cin >> x >> k;
		for (int i = 0; i < L; i++)
			if (k & (1 << i)) x = p[x][i];
		
		cout << x << "\n";
	}
	return 0;
}