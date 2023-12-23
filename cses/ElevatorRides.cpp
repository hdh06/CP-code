#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define st first
#define nd second

int const N = 20;

int n, x;
int w[N];

ii dp[1 << N];

ii emrua(int mask){
	if (mask == 0) return {1, 0};

	if (dp[mask].st != -1) return dp[mask];

	ii ans = {INT_MAX, INT_MAX};
	for (int i = 0; i < n; i++) if (mask & (1 << i)){
		ii p = emrua(mask ^ (1 << i));
		if (p.nd + w[i] <= x)
			p.nd += w[i];
		else{
			p.st++;
			p.nd = w[i];
		}
		ans = min(ans, p);
	}
	return dp[mask] = ans;
}


int main(){
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> w[i];

	memset(dp, -1, sizeof dp);

	cout << emrua((1 << n) - 1).st;
	return 0;
}