#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, x; cin >> n >> x;
	vector<int> arr(2 * n);
	for (auto &x: arr) cin >> x;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		if (arr[i + n] - arr[i] < x){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}