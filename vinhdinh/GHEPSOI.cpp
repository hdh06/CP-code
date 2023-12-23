#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	vector<ll> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());
	
	ll tong = arr[0], rtong = 0;
	for (int i = 1; i < n; i++){
		tong += arr[i];
		rtong += tong;
	}	

	cout << rtong;
	return 0;
}