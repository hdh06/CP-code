#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	int minn = arr[0], ans = 0;
	for (int i = 1; i < n; i++){
		ans = max(arr[i] - minn, ans);
		minn = min(arr[i], minn);
	} 	

	cout << ans;
	return 0;
}