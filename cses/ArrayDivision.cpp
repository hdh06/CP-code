#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;

int n, k;
int arr[N];

bool f(ll x){
	ll sum = 0;
	int dem = 0;
	for (int i = 1; i <= n; i++){
		if (sum + arr[i] <= x)
			sum += arr[i];
		else{
			sum = arr[i];
			dem++;
		}
		if (arr[i] > x) return 0;
	}
	return dem + 1 <= k;
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ll ans = -1;

	for (ll l = 0, r = 1e18; l <= r;){
		ll mid = (l + r) >> 1;
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}

	cout << ans;
	return 0;
}