#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 23;

ll n, k;
ll arr[N];

ll dequy(ll i, ll tong){
	if (i == 0){
		if (tong % k == 0) return 0;
		else return -1;
 	} 
	ll ans1 = dequy(i - 1, tong);
	ll ans2 = dequy(i - 1, tong + arr[i]);
	if (ans2 != -1) ans2 ++;
	return max(ans1, ans2);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << dequy(n, 0);
	return 0;
}