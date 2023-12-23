#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;

int main(){
	int n, d; cin >> n >> d;	
	int arr[N] = {};
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	int ans = 0;
	for (int l = 0, r = n; l < r;){
		ll cnt = 1;
		while (l < r - 1 && cnt * arr[r] <= d) l++, cnt++;
		if (cnt * arr[r] > d) ans++;
		r--;
	}
	cout << ans;
	return 0;
}