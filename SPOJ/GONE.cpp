#include <bits/stdc++.h>

using namespace std;

int const N = 11;
int const maxS = 200;

bool isPrime(int n){
	if (n <= 1) return false; 
	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;
}

int f(string s){
	int n = s.length();

	int dp[N][2][maxS] = {};
	dp[n][0][0] = dp[n][1][0] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int tight = 0; tight < 2; tight++){
			for (int sum = 0; sum < maxS; sum++){
				if (tight){
					for (int d = 0; d <= s[i] - '0'; d++){
						dp[i][1][sum]+= (d == s[i] - '0')?dp[i + 1][1][sum - d]:dp[i + 1][0][sum - d];
					}
				}
				else {
					for (int d = 0; d <= 9; d++) dp[i][0][sum] += dp[i + 1][0][sum - d];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < maxS; i++){
		if (isPrime(i)){
			ans += dp[0][1][i];
		}
		// cout <<"BEDBUG " << s << " " << i << ":" << dp[0][1][i] << endl;
	}
	return ans;
}

bool g(string a){
	int tong = 0;
	for (int i = 0; i < a.size(); i++){
		tong += a[i] - '0';
	}
	return isPrime(tong);
}

int main(){
	int t; 
	cin >> t; 

	while (t--){
		string a, b; 
		cin >> a >> b;
		cout << f(b) - f(a) + g(a) << endl;
	}

	return 0;
}