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

bool const SINGLE_TEST = 0;
int const MOD = 998244353;
int const N = 1e5 + 1;
int n;
int arr[N];

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * x % MOD;
	return 1LL * ans * ans % MOD;
}

int fact[N], inv[N], po2[N];
void init(){
	fact[0] = inv[0] = po2[0] = 1;
	for (int i = 1; i < N; i++){
		fact[i] = 1LL * fact[i - 1] * i % MOD;
		inv[i] = mpow(fact[i], MOD - 2);
		po2[i] = 1LL * po2[i - 1] * 2 % MOD;
	}
}

int C(int k, int n){
	if (k > n) return 0;
	return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int c(int x, int y){
	int ans = 0;
	for (int i = 0; i <= min(x, y); i++)
		(ans += 1LL * C(i, x) * C(i, y) % MOD) %= MOD;
	return ans;
}

int calc(int l, int r){
	if (r < l) return 1;
	int i = l, j = r;
	while (i <= r && arr[i] == 0) i++;
	while (j >= l && arr[j] == 0) j--;
	if (i == r + 1) return po2[r - l];
	if (l < i && j < r) return 1LL * c(i - l, r - j) * calc(i, j) % MOD;
	i = l, j = r + 1;
	ll a = arr[i], b = 0;
	while (1){
		while (j > l && b < a)
			b += arr[--j];
		if (i == r || j == l) return 1;
		if (j != r + 1 && a == b) break;
		a += arr[++i];
	}
	int l0 = i + 1, r0 = j - 1;
	while (l0 < j && arr[l0] == 0) l0++;
	while (r0 > i && arr[r0] == 0) r0--;
	if (l0 == j) return po2[j - i];
	return 1LL * c(l0 - i, j - r0) * calc(l0, r0) % MOD; 	
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];	
	cout << calc(1, n) << "\n";
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