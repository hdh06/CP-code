#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

int const N = 1e4 + 1;
int const M = 1e5 + 1;

int par[N] = {};
vector<iii> ea, eb;
int n, m;
int a[N] = {}, b[N] = {};
bool take[M] = {};

int find(int x){
	if (par[x] != x) par[x] = find(par[x]);
	return par[x];
}

bool unite(int a, int b){
	a = find(a); b = find(b);
	if (a == b) return 0;
	par[a] = b;
	return 1;
}

void init(int n){
	for (int i = 1; i <= n; i++)
		par[i] = i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		ea.clear(); eb.clear();
		cin >> n >> m;	

		for (int i = 1; i <= n - 1; i++) cin >> a[i];
		for (int i = 1; i <= n - 1; i++) cin >> b[i];
		
		for (int i = 1; i <= m; i++){
			int a, b, c; cin >> a >> b >> c;
			if (c == 1)
				ea.push_back({a, b, i});
			else
				eb.push_back({a, b, i});
		}

		init(n); int max1 = 0;
		for (auto e: ea) if (unite(e[0], e[1])) max1++;
		init(n); int max2 = 0;
		for (auto e: eb) if (unite(e[0], e[1])) max2++;
		int min1 = n - 1 - max2;

		int x = -1; int minn = INT_MAX;
		for (int i = min1; i <= max1; i++){
			if (a[i] + b[n - 1 - i] < minn){
				minn = a[i] + b[n - 1 - i];
				x = i;
			}
		}

		for (int i = 1; i <= m; i++) take[i] = 0;

		init(n);
		for (auto e: eb) unite(e[0], e[1]);
		for (auto e: ea) take[e[2]] = unite(e[0], e[1]);

		init(n);
		for (auto e: ea) if (take[e[2]]){
			unite(e[0], e[1]);
			x--;
		}
		
		if (x != 0) for (auto e: ea) if (unite(e[0], e[1])){
			take[e[2]] = 1;
			x--;
			if (x == 0) break;
		}
		for (auto e: eb) take[e[2]] = unite(e[0], e[1]);

		for (int i = 1; i <= m; i++) if (take[i]) cout << i << " "; 
		cout << "\n";
	}
	return 0;
}