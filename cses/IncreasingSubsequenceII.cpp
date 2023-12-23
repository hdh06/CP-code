#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const MOD = 1e9 + 7;

void compress(vector<int> &arr){
	set<int> s(arr.begin(), arr.end());
	vector<int> b(s.begin(), s.end());
	for (auto &x: arr){
		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
	}
}

int tree[N];
void upd(int k, int x){
	for (int i = k; i < N; i += (i & -i)) (tree[i] += x) %= MOD;
}
int get(int k){
	int ans = 0;
	for (int i = k; i > 0; i -= (i & -i)) (ans += tree[i]) %= MOD;
	return ans;
}

int main(){
	int n; cin >> n;
	vector<int>	arr(n);
	for (auto &x: arr) cin >> x;

	compress(arr);

	for (auto x: arr){
		// cout << get(x - 1) + 1 << " ";
		upd(x, get(x - 1) + 1);
	}

	cout << get(n);
	return 0;
}