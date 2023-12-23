#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll emrua(int k, vector<ll> v){
	if (k == 0) return 0;

	int n = v.size();

	ll ans = LLONG_MIN;
	ans = max(ans, emrua(k - 1, vector<ll>(v.begin(), v.end() - 3)) + v[n - 1] * v[n - 2] * v[n - 3]);
	ans = max(ans, emrua(k - 1, vector<ll>(v.begin() + 3, v.end())) + v[0] * v[1] * v[2]);
	ans = max(ans, emrua(k - 1, vector<ll>(v.begin() + 2, v.end() - 1)) + v[0] * v[1] * v[n - 1]);
	ans = max(ans, emrua(k - 1, vector<ll>(v.begin() + 1, v.end() - 2)) + v[0] * v[n - 2] * v[n - 1]);
	return ans;
}

int main(){
	int n, k; cin >> n >> k;
	vector<ll> arr(n);
	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	cout << emrua(k, arr);
	return 0;
}