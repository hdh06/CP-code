#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("Chess.inp", "r", stdin);
	// freopen("Chess.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		cout << a[i] << " " << b[i] << "\n";

	int ans = 0;
	for (int i = 0, j = 0; i < n && j < n;){
		if (b[i] >= a[j]){
			if (i < n - 1 && b[i] == a[j] && b[i + 1] > a[j] && b[i + 1] <= a[j + 1]) i++;
			ans += 2 - (b[i] == a[j]);
			i++, j++;
		}else i++;
	}
	cout << ans;
	return 0;
}