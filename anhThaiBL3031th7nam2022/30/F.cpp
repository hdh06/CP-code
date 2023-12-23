#include <bits/stdc++.h>

using namespace std;

int num(char c){return c - '0';}
char chr(int c){return c + '0';}

string div3(string s){
	string ans;
	int du = 0;
	for (int i = 0; i < s.size(); i++){
		du = du * 10 + num(s[i]);
		ans += chr(du / 3);
		du %= 3;
	}
	if (s.size() != 1 && ans[0] == '0') ans.erase(0, 1);
	return ans;
}

int mod3(string s){
	int sum = 0;
	for (auto x: s) sum += num(x);
	return sum % 3;
}

string b3c(string s){
	string ans;
	while (s != "0"){
		ans += chr(mod3(s));
		s = div3(s);
	}
	return string(ans.rbegin(), ans.rend());
}

int const N = 3e3 + 1;
int const K = 1e3 + 1;
int const MOD = 1e9 + 7;

int dp[N][K] = {};

int emrua(int n, int k){
	if (k < 0) return 0;
	if (n == 0) return 1;

	if (dp[n][k] != -1) return dp[n][k];

	int ans = 0;
	for (int i = 0; i <= 2; i++)
		(ans += emrua(n - 1, k - i)) %= MOD;

	return dp[n][k] = ans;	
}

void inc(string &s){
	s = '0' + s;
	int i = s.size() - 1;
	while (s[i] == '2') i--;
	s[i]++;
	while (i < s.size()) s[++i] = '0';
	if (s[0] == '0') s.erase(0, 1);
}

int calc(string s, int k){
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		for (int j = 0; j < num(s[i]); j++)
			(ans += emrua(s.size() - i - 1, k - j)) %= MOD;
		k -= num(s[i]);
	}
	return ans;
}

void solve(){
	string L, R;
	cin >> L >> R;

	L = b3c(L);
	R = b3c(R);

	inc(R);

	int k; cin >> k;

	cout << (calc(R, k) - calc(L, k) + MOD) % MOD << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	memset(dp, -1, sizeof dp);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
