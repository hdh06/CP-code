#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int main(){
	int n; 
	cin >> n; 

	int dp[N] = {}, arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) if (gcd(arr[j],arr[i]) == 1){
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}