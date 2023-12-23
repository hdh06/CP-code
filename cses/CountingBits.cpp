#include <bits/stdc++.h>

using namespace std;

int const N = 50;

typedef long long ll;

ll cal[N] = {};

int main(){
	ll n; cin >> n;

	for (int i = 1; i < N; i++)
		cal[i] = cal[i - 1] * 2 + (1LL << (i - 1));

	ll l = 0, ans = 0, dem = 0;
	for (int i = N - 1; i >= 0; i--)
		if (n - l + 1 >= (1LL << i)){
			ans += cal[i] + 1LL * dem * (1LL << i);
			dem++;
			l += 1LL << i;
		}
	
	cout << ans;
	return 0;
}
