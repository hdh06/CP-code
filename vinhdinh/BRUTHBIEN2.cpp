#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t, m;
	cin >> n >> t >> m;

	if (m > n){
		cout << 0;
		return 0;
	}

	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	multiset<int> myset;
	
	for (int i = 1; i <= m; i++)
		myset.insert(arr[i]);

	int ans = 0;

	for (int i = m + 1; i <= n; i++){
		ans += *myset.rbegin() <= t;
		// cout << *myset.rbegin() << endl;
		myset.erase(myset.lower_bound(arr[i - m]));
		myset.insert(arr[i]);
	}

	ans += *myset.rbegin() <= t;
	// cout << *myset.rbegin() << endl;

	cout << ans;
	return 0;
}