#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 20;

int num(char c){
	return c - '0';
}

ll f(string s){
	int n = s.size();

	ll dp[N][2][11] = {};
	dp[n][1][0] = dp[n][0][0] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int tight = 0; tight < 2; tight++){
			if (tight){
				for (int state = 1; state <= num(s[i]) + 1; state++)
				for (int d = 0; d <= 10; d++)if (d != state){
					dp[i][1][state] += (state == num(s[i]) + 1)?dp[i + 1][1][d]:dp[i + 1][0][d];
				}
			}
			else{
				for (int state = 1; state <= 10; state++)
				for (int d = 0; d <= 10; d++) if (d != state){
					dp[i][0][state] += dp[i + 1][0][d];
			}
		}
	}
}

	ll ans = 0;
	for (int i = 0; i <= n - 1; i++){
		ans += (i == 0)?dp[i][1][1]:dp[i][0][1];
	}

	// for (int i = 0; i <= 10; i++){
	// 	cout << "BEDBUG [" << i <<"]: " ;
	// 	for (int j = 0; j <= n - 1; j++){
	// 		cout << "[" << j << "] " << dp[j][1][i] << " " << dp[j][0][i] << " \n"[j == n-1]; 
	// 	}
	// }
	for (int state = 2;state <= 10; state ++) ans += dp[0][1][state];

	return ans;
}

bool g(string s){
	for (int i = 1; i < s.length(); i++) if (s[i] == s[i - 1]) return false;
	return true;
}

int main(){
	string a, b; 
	cin >> a >> b;
	cout << f(b) - f(a) + g(a);
	return 0;
}