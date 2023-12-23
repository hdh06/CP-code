#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	ll tong = 0;
	for (auto x: arr){
		if (x > tong + 1){
			cout << tong + 1;
			return 0;
		}
		tong += x;
	}	
	cout << tong + 1;
	return 0;
}