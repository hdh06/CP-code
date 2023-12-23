#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 2> ii;

vector<ii> a, b;

int n; ll m;

unordered_map<ll, ll> A, B;

void dequy(int i, ll s, ll v, map<ll, ll> &mm, vector<ii> arr){
	if (s > m) return;
	if (i == arr.size()){
		mm[s] = max(mm[s], v);
		return; 
	}
	dequy(i + 1, s + arr[i][0], v + arr[i][1], mm, arr);
	dequy(i + 1, s, v, mm, arr);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int w, v;
		cin >> w >> v;
		if (i & 1) a.push_back({w, v});
		else b.push_back({w, v});
	}

	dequy(0, 0, 0, A, a);
	dequy(0, 0, 0, B, b);

	B[LLONG_MAX] = 0;

	ll ans = 0, maxn = 0;

	for (auto &x: B){
		ll temp = x.second;
		x.second = maxn;
		maxn = max(maxn, temp);
	}

	for (auto x: A)
		ans = max(ans, x.second + (*B.upper_bound(m - x.first)).second);

	cout << ans;
	return 0;
}