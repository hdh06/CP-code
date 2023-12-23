#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int arr[N], brr[N];

void solve(){
	int n; cin >> n;	
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		brr[i] = arr[i];
	}
	if (n == 1){
		cout << -1 << "\n";
		return;
	}

	sort(brr + 1, brr + n + 1);
	for (int i = 1; i <= n - 1; i++){
		if (arr[i] == brr[i])
			swap(brr[i], brr[i + 1]);
	}
	if (arr[n] == brr[n]) swap(brr[n], brr[n - 1]);
	for (int i = 1; i <= n; i++)
		cout << brr[i] << " \n"[i == n];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}