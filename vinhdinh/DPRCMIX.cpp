#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 101;

ll dp[N][N];

int n;
int psum[N] = {};

void init(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) dp[i][j] = -1;
		psum[i] = 0;
	}
}

ll sum(int a, int b){return (psum[b] - psum[a - 1]) % 100;};

ll dequy(int i, int j){
	if (i == j) return 0;
	if (i + 1 == j) return 1LL*sum(i, i)*sum(j, j);

	if (dp[i][j] != -1) return dp[i][j];

	ll ans = LLONG_MAX;

	for (int k = i; k <= j - 1; k++){
		ans = min(ans, dequy(i, k) + dequy(k + 1, j) + 1LL*sum(i, k)*sum(k + 1, j));
	}	
	return dp[i][j] = ans;
}

int main(){
	while(cin >> n){
		init();
		for (int i = 1; i <= n; i++){
			int t; cin >> t;
			psum[i] = psum[i - 1] + t;
		}
		cout << dequy(1, n) << "\n";
	}
	return 0;
}