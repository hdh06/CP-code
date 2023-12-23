#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, bool> A, B;
vector<int> a, b;

bool dequy(int i, ll s, map<ll, bool> &m, vector<int> arr){
	if (i == arr.size()) return m[s] = true;

	dequy(i + 1, s + arr[i], m, arr);
	dequy(i + 1, s, m, arr);
}

int main(){
	int n; cin >> n;
	ll tong = 0;
	while (n--){
		int t; cin >> t;
		if (n & 1) a.push_back(t);
		else b.push_back(t);
		tong += t;
	}		

	dequy(0, 0, A, a);
	dequy(0, 0, B, b);

	ll ans = INT_MAX;

	for (auto x: A){
		if (B[tong - x.first]) ans = min(ans, abs(x.first - (tong - x.first)));
	}

	cout << ans;

	return 0;
}