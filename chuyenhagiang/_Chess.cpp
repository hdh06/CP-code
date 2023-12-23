#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;

int n;
int a[N], b[N];

int calc(){
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (b[i] > a[i]) ans += 2;
		else if (b[i] == a[i]) ans++;
	return ans;
}

int main(){
	freopen("Chess.inp", "r", stdin);
	freopen("Chess.ans", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	sort(a, a + n);

	int ans = 0;
	do{
		ans = max(ans, calc());
	} while (next_permutation(a, a + n));
	cout << ans;
	return 0;
}