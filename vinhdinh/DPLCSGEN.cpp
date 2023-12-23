#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const P = 3e6;
int const N = 1001;

bool sang[P] = {1, 1};

void init(){
	for (ll i = 2; i < P; i++) if (!sang[i])
		for (ll j = i * i; j < P; j += i) sang[j] = true;
}

bool check1(ll n){
	ll can = sqrt(n);
	return (can*can == n);
}

bool check2(ll n){
	ll can = cbrt(n);
	if (can*can*can == n && !sang[can]) return true;
	return false;
}

int main(){
	init();
	
	vector<ll> a(1, 0), b(1, 0);

	string s; stringstream ss; ll t;
	getline(cin, s);
	ss << s; 
	while (ss >> t) a.push_back(t);
	ss.clear();
	getline(cin, s);
	ss << s;
	while (ss >> t) b.push_back(t);

	int n = a.size() - 1, m = b.size() - 1;
	int dp[N][N] = {};
 	
 	for (int i = 1; i <= n; i++)
 		for (int j = 1; j <= m; j++)
 			if (a[i] == b[j] && (check1(a[i]) || check2(a[i]))){
 				dp[i][j] = dp[i - 1][j - 1] + 1;
 			}
 			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
 	
 	// for (int i = 1; i <= n; i++)
 	// 	for (int j = 1; j <= m; j++) cout << dp[i][j] << " \n"[j == m];
 	cout << dp[n][m];
	return 0;
}