#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 3> iii;

void compress(vector<iii> &arr){
	set<int> s;
	for (auto x: arr){
		s.insert(x[0]);
		s.insert(x[1]);
	}
	vector<int> b(s.begin(), s.end());
	for (auto &x: arr){
		x[0] = lower_bound(b.begin(), b.end(), x[0]) - b.begin() + 1;
		x[1] = lower_bound(b.begin(), b.end(), x[1]) - b.begin() + 1;
	}
}

int const N = 2e5 + 1;
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
	vector<iii> arr(n);
	for (auto &x: arr) cin >> x[0] >> x[1] >> x[2];

	sort(arr.begin(), arr.end(), [](iii a, iii b){
		return a[1] < b[1];
	});

	compress(arr);

	for (auto x: arr){
		upd(x[1], get(x[0] - 1) + x[2]);
	}

	cout << get(n);
	return 0;
}