#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;

int tree[N][N];
void upd(int x, int y, int k){
	for (int i = x; i < N; i += i & -i)
		for (int j = y; j < N; j += j & -j)
			tree[i][j] = max(tree[i][j], k);
}

int get(int x, int y){
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j)
			ans = max(ans, tree[i][j]);
	return ans;
}

int main(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	for (int i = 0; i < n; i++)
		upd(a[i], b[i], get(a[i] - 1, b[i] - 1) + 1);

	cout << get(N - 1, N - 1);
	return 0;
}