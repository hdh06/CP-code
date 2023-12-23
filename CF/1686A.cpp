#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int arr[51];
	int sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];
	}	

	for (int i = 1; i <= n; i++){
		if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}