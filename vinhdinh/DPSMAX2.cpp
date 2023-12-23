#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void compress(vector<int> &arr){
	set<int> s(arr.begin(), arr.end());
	vector<int> b(s.begin(), s.end());
	for (auto &x: arr) x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

int const N = 1e5 + 1;
ll tree[N];
void upd(int x, ll s){
	for (int i = x; i < N; i += (i & -i)) tree[i] = max(tree[i], s);
}
ll get(int x){
	ll ans = 0;
	for (int i = x; i > 0; i -= (i & -i)) ans = max(ans, tree[i]);
	return ans; 
}


int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	vector<int> b(arr.begin(), arr.end());
	compress(b);

	ll ans = 0;

	for (int i = 0; i < n; i++){
		upd(b[i], get(b[i]) + arr[i]);
		ans = max(ans, get(b[i]));
	}

	cout << ans;
	return 0;
}