#include <bits/stdc++.h>

using namespace std;

int const N = 201;

string arr;
int dp[N];

int dequy(int n){
	if (n == 0) return 0;

	if (dp[n] != -1) return dp[n];

	int a = 0, b = 0;
	int ans = 0;
	for (int i = n; i >= 1; i--){
		if (arr[i] == '1') a++;
		else b++;
		ans = max(ans, (a > b?a + b:0) + dequy(i - 1));
	}
	return dp[n] = ans;
}

int main(){
	int t; cin >>t;
	while (t--){
		int n; 
		cin >> n;

		for (int i = 1; i <= n; i++) dp[i] = -1;

		cin >> arr;
		arr = ' ' + arr;
		cout << dequy(n) << "\n";
	}
	return 0;
}