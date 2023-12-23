#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 2;
int const MOD = 1e9 + 7;

pair<int, int> dp[N][11];
bool ismemo[N][11];

string s;

int num(char x){return x - '0';}

int pre[N];
void init(){
	pre[0] = 1;
	for (int i = 1; i < N; i++)
		pre[i] = 1LL * pre[i - 1] * 10 % MOD;
}

pair<int, int> emrua(int n, int last){
	if (n == 0)
		return {0, 1};

	if (ismemo[n][last]) return dp[n][last];
	
	int ans = 0; int dem = 0;
	for (int i = 0; i <= 9; i++){
		pair<int, int> p = emrua(n - 1, i);
		(ans += (p.first + 1LL * p.second * (last != i? 1LL * i * pre[n - 1] % MOD: 0ll) % MOD) % MOD) %= MOD;
		(dem += p.second) %= MOD;
	}
	ismemo[n][last] = 1;
	return dp[n][last] = {ans, dem};
}

int calc(string s){
	int ans = 0;
	int sum = 0;
	int last = 10;
	for (int i = 0; i < s.size(); i++){
		for (int j = 0; j < num(s[i]); j++){
			pair<int, int> p = emrua(s.size() - i - 1, j);
			(ans += (1LL * (sum + (last != j?1LL * j * pre[s.size() - i - 1] % MOD: 0LL)) % MOD *p.second % MOD + p.first) % MOD) %= MOD;
		}
		(sum += (last != num(s[i])?1LL * num(s[i]) * pre[s.size() - i - 1] % MOD: 0LL)) %= MOD;
		last = num(s[i]);
	}
	return ans;
}

void inc(string &s){
	s = '0' + s;
	int x = s.size() - 1;
	while (s[x] == '9') x--;
	s[x]++;
	while (x < s.size()) s[++x] = 0;
	if (s[0] == '0') s.erase(0, 1);
}

void solve(){
	string L, R; cin >> L >> R;
	inc(R);
	cout << (calc(R) - calc(L) + MOD) % MOD<< "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	init();
	int t; cin >> t;
	while(t--) solve();
	return 0;
}