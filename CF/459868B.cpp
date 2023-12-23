#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 20;

int n;
int a[N][N];

ll dp[N][1 << N];

ll calc(int i, int mask){
	if (i == n) return 0;
	
	ll &ans = dp[i][mask];
	if (ans != -1) return ans;
	ans = LLONG_MIN;
	for (int j = 0; j < n; j++) if (~mask & (1 << j))
		ans = max(ans, calc(i + 1, mask | (1 << j)) + a[i][j]);
	
	return ans;
}


int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
		
	memset(dp, -1, sizeof dp);
	
	cout << calc(0, 0);
	return 0;
}