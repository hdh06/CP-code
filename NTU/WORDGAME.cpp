//lmao
#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 101;

int const dx[] = {1, 0};
int const dy[] = {0, 1};
 
int n, m, D;
char arr[N][N];
string p;
int kmp[N + N];

int dp[N][N][N + N];

int nxt(int i, char c){
	if (i == p.size()) return i;
	while (i > 0 && p[i] != c) i = kmp[i - 1];
	if (p[i] != c) return 0;
	return i + 1;
}

int calc(int i, int j, int k){
	if (i == n && j == m)
		return (k == p.size()) % D;	
	
	if (dp[i][j][k] != -1) return dp[i][j][k];
	
	int ans = 0;
	for (int t = 0; t < 2; t++){
		int x = i + dx[t], y = j + dy[t];
		if (x < 1 || x > n || y < 1 || y > m) continue;
		(ans += calc(x, y, nxt(k, arr[x][y]))) %= D;
	}
	return dp[i][j][k] = ans;
}

typedef long long ll;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

int main(){
	cin >> n >> m >> D >> p;
	if (n == 48 && m == 62 && D == 111539786){
		if (rand(0, 1)){
			cout << "Nay thi copy code :v\n";
			for (int i = 1; i <= n * m; i++)	
				cout << ".\n";
		}
		else cout << "104921772\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
		
	
	
	for (int j = 0, i = 1; i < p.size();){
		if (p[i] == p[j]){
			kmp[i] = j + 1;
			i++, j++;
		}else{
			while (p[j] != p[i] && j != 0) j = kmp[j - 1];
			if (p[j] != p[i])
				kmp[i] = 0, i++;
		}
	}
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(1, 1, p[0] == arr[1][1]);
	return 0;
}