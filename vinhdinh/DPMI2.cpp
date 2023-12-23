#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e8;

int n;
pair<int, int> arr[N];
#define st first
#define nd second

int dp[N];

void solve(){
	for (int i = 1; i <= n; i++)
		cin >> arr[i].nd >> arr[i].st;
		
	sort(arr + 1, arr + n + 1);
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		int k = upper_bound(arr + 1, arr + n + 1, make_pair(arr[i].nd, INT_MAX)) - arr - 1;
		dp[i] = (dp[i - 1] + dp[k]) % MOD;
	}
	
	cout << setfill('0') << setw(8) << (dp[n] - 1 + MOD) % MOD << "\n";
}

int main(){	
	cin >> n;
	while (n != -1){
		solve();
		cin >> n;
	}
	return 0;
}