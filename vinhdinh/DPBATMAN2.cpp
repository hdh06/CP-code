#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;


int n, m;
ll h[N];

int tree[N];
void upd(int k, int val){
	for (;k > 0; k -= k & -k)
		tree[k] = max(tree[k], val);
}
int get(int k){
	int ans = 0;
	for (;k < N; k += k & -k)
		ans = max(ans, tree[k]);
	return ans;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	
	{
		vector<ll> b(h + 1, h + n + 1);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		
		for (int i = 1; i <= n; i++)
			h[i] = lower_bound(b.begin(), b.end(), h[i]) - b.begin() + 1;
	}
	
	memset(tree, 0, sizeof tree);
	
	
	int p = 0;
	for (int i = 1; i <= n; i++){
		if (i == m) p = get(h[i] + 1) + 1;
		upd(h[i], max(p + 1, get(h[i] + 1) + 1));
	}
		
	cout << get(1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}