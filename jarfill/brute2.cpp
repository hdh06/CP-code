#include <bits/stdc++.h>

using namespace std;

int const N = 5e5 + 5;

typedef long long ll;

int n, q;
int l, r, k, x;  
ll arr[N];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> q;

	ll diff[N] = {};

	bool flag = 0;
	while (q--){
		cin >> l >> r >> k >> x;
		if (k == 1){
			diff[l] += x;
			diff[r + 1] -= x;
		}else{
			flag = 1;
			if (l & 1) l++;
			if (r & 1) r--;
			diff[l] += x;
			diff[r + 1] -= x;
		}
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += diff[i];
		if (!flag || i % 2 == 0) cout << sum << " ";
		else cout << "0 ";
	}
	return 0;
}