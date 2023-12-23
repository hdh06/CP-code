#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

vector<int> sang[N];
int f[N];

void init(){
	for (int i = 2; i < N; i++) if (sang[i].empty())
		for (int j = i; j < N; j += i) sang[j].push_back(i);
}

int main(){
	init();
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	int res = 0;

	for (auto x: arr){
		int ans = 1;
		for (auto y: sang[x]) ans = max(ans, f[y] + 1);
		for (auto y: sang[x]) f[y] = ans;
		// cout << ans << ' ';
		res = max(res, ans);
	}

	cout << res;
	return 0;
}
    