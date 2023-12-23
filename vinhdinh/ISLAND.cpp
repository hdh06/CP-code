#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 2> ii;

int const N = 200001;

int link[N];
int sz[N];
ll tong = 0;

int find(int x){
	if (x != link[x]) link[x] = find(link[x]);
	return link[x];
}

bool join(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return false;
	tong -= 1LL*sz[a]*sz[b];
	link[b] = a;
	sz[a] += sz[b];
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;

	vector<ii> edges(m);

	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) sz[i] = 1;

	for (auto &x: edges) cin >> x[0] >> x[1];

	reverse(edges.begin(), edges.end());

	vector<ll> ans;
	tong = 1LL*n*(n - 1)/2;

	for (auto x: edges){
		ans.push_back(tong);
		join(x[0], x[1]);
	}

	reverse(ans.begin(), ans.end());
	for (auto x: ans) cout << x << "\n";
	return 0;
}