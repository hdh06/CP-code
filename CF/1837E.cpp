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

int const K = 20;
int const N = 1 << K;
int const MOD = 998244353;

int p2[N], fact[N];
void init(){
	p2[0] = fact[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i  % MOD;
		p2[i] = p2[i - 1] * 2 % MOD;
	}
}

int k;
int p[N];

int get(int l, int r, int d){
	int maxx = -1;
	for (int i = l; i <= r; i++) if (p[i] != -1 && p[i] <= 2 * d){
		if (maxx == -1 || p[i] < maxx)
			maxx = p[i];
	}
	return maxx;
}

void solve(){
 	cin >> k;
	for (int i = 1; i <= (1 << k); i++)
		cin >> p[i];

	int ans = 1;
	for (int i = k; i >= 1; i--){
		int d = (1 << k) / (1 << i);
		int cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= (1 << k); j += 1 << i){
			int m1 = get(j, j + (1 << (i - 1)) - 1, d);
			int m2 = get(j + (1 << (i - 1)), j + (1 << i) - 1, d);
			if (m2 != -1 && m2 <= d) swap(m1, m2);
			if (m1 != -1 && m1 > d) swap(m1, m2);
			if (m1 != -1 && m1 > d) ans *= 0;
			if (m2 != -1 && m2 <= d) ans *= 0;
			if (m1 == -1 && m2 == -1) cnt1++;
			if (m2 == -1) cnt2++;
		}
		
		ans = 1LL * ans * p2[cnt1] % MOD;
		ans = 1LL * ans * fact[cnt2] % MOD;
	}
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	init();
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!