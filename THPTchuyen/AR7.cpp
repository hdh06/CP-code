#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	for (auto x: arr) cout << x << " ";	
	return 0;
}