#include <bits/stdc++.h>

using namespace std;

int const maxS = 90;
int const N = 11;
typedef long long ll;

ll f(int x){
	if (x == -1) return 0;
	stringstream ntos; 
	ntos << x; 
	string s; 
	ntos >> s; 
	int n = s.size();

	ll dp[N][2][maxS] = {};

	dp[n][0][0] = 1;
	dp[n][1][0] = 1;

	for (int i = n - 1; i >= 0; i--){
		for (int tight = 0; tight <= 1; tight++){
			for (int sum = 0; sum < maxS; sum++){
				// dp[i][0][sum] = dp[i][1][sum] = 0;
				if (tight){
					for (int d = 0; d <= s[i] - '0'; d++){
						dp[i][1][sum] += (s[i] - '0' == d)?dp[i + 1][1][sum - d]: dp[i + 1][0][sum - d]; 
					}
				}
				else for (int d = 0; d <= 9; d++){
					dp[i][0][sum] += dp[i + 1][0][sum - d];
				}
				// cout << "hello" << tight << " " << i << endl;
			}
		}
	}


	ll tong = 0;
	for(int i = 0; i < maxS; i++){
		tong += i * dp[0][1][i];
	}
	return tong;
}

int main(){
	int a, b;
	cin >> a >> b;

	while (a != -1){
		cout << f(b) - f(a - 1) << endl;
		cin >> a >> b;
	}
	return 0;
}