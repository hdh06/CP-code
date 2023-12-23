#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

typedef long long ll;

void solve(){
	int n; cin >> n;
	int arr[N];	
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ll ans = 0;
	for (int j = 1, i = 2; i < n;){
		while (i < n && arr[i] != 0) i++;
		while (j < i && arr[j] == 0) j++;
		if (arr[j] > 0) arr[j]--, arr[i]++, ans++;
		i++;
	}	

	for (int i = 1; i < n; i++) ans += arr[i];
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}