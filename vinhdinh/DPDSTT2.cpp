#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int f[N];

vector<int> pf(int x){
	vector<int> ans;
	if (x % 2 == 0) ans.push_back(2);
		while (x % 2 == 0) x /= 2;
	for (int i = 3; i <= sqrt(x); i += 2){
		if (x % i == 0) ans.push_back(i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) ans.push_back(x);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	int res = 0;

	for (auto x: arr){
		int ans = 1;
		vector<int> p = pf(x);
		for (auto y: p) ans = max(ans, f[y] + 1);
		for (auto y: p) f[y] = ans;
		res = max(res, ans);
	}

	cout << res;
	return 0;
}