#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 5;

typedef long long ll;

int n, q;
int l, r, k, x;  
ll arr[N];

int main(){
	// freopen("gen.inp", "r", stdin);
	// freopen("brute.out", "w", stdout);
	cin >> n >> q;

	while (q--){
		cin >> l >> r >> k >> x;
		for (int i = l; i <= r; i++)
			if (i % k == 0) arr[i] += x;
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	return 0;
}