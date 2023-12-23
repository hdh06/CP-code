#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...)
#endif


using namespace std;

typedef long double ldb;

int const LIM = 121;

int const N = 5e4 + 1;

vector<int> g[N];

int n;

bool vis[N][LIM];
ldb dp[N][LIM];

ldb calc(int p, int d){
	if (d > LIM) return 0;
	if (p == 1) return 0;
	if (vis[p][d]) return dp[p][d];
	if (d & 1){
		ldb minn = 1e9;
		for (auto u: g[p]){
			minn = min(minn, calc(u, d + 1) + 1);
		}
		vis[p][d] = 1;
		return dp[p][d] = minn;
	}else{
		ldb ans = 0;
		for (auto u: g[p])
			ans += calc(u, d + 1);
		ans = 1.0L * ans / (1.0L * (n - 1));
		vis[p][d] = 1;
		return dp[p][d] = ans + 1;
	}
}

int main(){
	cin >> n;
	vector<int> p(n), A(n);
	for (int i = 0; i < n; i++){ 
		cin >> p[i];
		A[i] = i + 1;
	}
	map<vector<int>, int> ids; int id = 0;
	do{
		ids[A] = ++id;
	}while (next_permutation(A.begin(), A.begin() + n));
	do{
		int x = ids[A];
		for (int i = 0; i < n - 1; i++){
			swap(A[i], A[i + 1]);
			g[x].push_back(ids[A]);
			swap(A[i], A[i + 1]);
		}
	}while (next_permutation(A.begin(), A.begin() + n));

	cout << setprecision(5) << fixed << calc(ids[p], 1) << "\n";
	return 0;
}