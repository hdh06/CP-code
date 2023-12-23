#include <bits/stdc++.h>

using namespace std;

int n, k;

int c(int x){
	int z = log2(n);
	return ~x & ((1 << z) - 1);
}

void solve(){
	cin >> n >> k;
	if (k == 0)
		for (int i = 0; i < n / 2; i++) cout << i << " " << c(i) << "\n";
	else if (k == n - 1){
		if (n == 4) cout << "-1\n";
		else{
			for (int i = 3; i < n / 2; i++) cout << i << " " << c(i) << "\n";
			cout << n - 1 << " " << n - 2 << "\n";
			cout << n - 3 << " " << 1 << "\n";
			cout << 2 << " " << 0 << "\n";
		}
	}
	else{
			for (int i = 1; i < n / 2; i++) if (i != k && i != c(k))
				cout << i << " " << c(i) << "\n";
			cout << 0 << " " << c(k) << "\n";
			cout << k << " " << n - 1 << "\n";
		}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}