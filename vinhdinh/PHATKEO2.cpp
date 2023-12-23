#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, k; 
	cin >> n >> k;

	int dem = 0; ll tong = 0;
	for (ll boi = 1; dem <= n && tong <= k; dem++, tong += boi, boi += 3);

	cout << dem - (tong > k || dem > n);
	return 0;
}