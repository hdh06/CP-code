#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n; int k; 
	cin >> n >> k;
	ll arr[20];
	for (int i = 0; i < k; i++) cin >> arr[i];

	ll ans = 0;
	for (int mask = 1; mask < (1 << k); mask++){
		int d = 0; ll z = n;
		for (int i = 0; i < k; i++) if (mask & (1 << i))
			z /= arr[i], d++;
		ans += z * (d & 1? 1: -1);
	}
	cout << ans;
	return 0;
}