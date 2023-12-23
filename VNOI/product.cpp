#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

ll mod(string s, int b){
	int n = s.size();
	ll du = 0;
	for (int i = 0; i < n; i++){
		du = du * 10 + (s[i] - '0');
		du %= b;
	}
	return du;	
}

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

void solve(){
	int f[N] = {1}, inv[N] = {1};
	long double l[N] = {0};
	for (int i = 1; i < N; i++){
		f[i] = 1LL * f[i - 1] * i % MOD;
		inv[i] = mpow(f[i], MOD - 2);
		l[i] = l[i - 1] + log10(i);		
	}
			
	string P; cin >> P;
	ll z = mod(P, MOD);
	int y = P.size() - 1;
	// debug(z, y);
	for (int i = 1, j = 1;j < N;j++){
		while (i < j && int(l[j] - l[i - 1]) > y) i++;
		while (i > 1 && int(l[j] - l[i - 1]) <= y) i--;
		
		for (int k = i; k <= j; k++)
			if (1LL * f[j] * inv[k - 1] % MOD == z){
				cout << k << " " << j << '\n';
				return;	
			}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!