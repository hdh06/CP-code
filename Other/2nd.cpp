#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("2nd.inp", "r", stdin);
	freopen("2nd.out", "w", stdout);
	int n; cin >> n;
	
	vector<int> a(n), b(n);
	
	for (auto &x: a) cin >> x;
	for (auto &x: b) cin >> x;
	int k; cin >> k;
	
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (auto x: a){
		if (x % 2 == 0) ans1 += x;
		if (x == k) ans2 = 1;
	}
	for (auto x: b){
		if (x % 2 == 0) ans1 += x;
		if (x == k) ans2 = 1;
	}
	
	vector<int> c;
	for (int i =0; i < n; i++){
		c.push_back(b[i]);
		c.push_back(a[i]);
	}
	
	cout << "Tong so chan 2 mang: " << ans1 << "\n";
	cout << (ans2? "Co ": "Khong co ") << k << " trong A hoac B\n";
	cout << "C: ";
	for (auto x: c)
		cout << x << " ";
	return 0;
}