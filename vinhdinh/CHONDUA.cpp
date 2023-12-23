#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin >> n;

	vector<int> a(n + 1), b(n);

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(b.begin(), b.end());
	
	ll tong = 0;
	for (int i = 1; i <= n; i++){
		int k = upper_bound(b.begin(), b.end(), a[i]) - lower_bound(b.begin(), b.end(), a[i]);
		tong += (ll)n - (ll)k;
	}

	cout << tong;
	
	return 0;
}