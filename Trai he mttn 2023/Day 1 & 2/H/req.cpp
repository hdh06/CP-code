#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

typedef long long ll;

int const N = 4e5 + 1;
int const V = 1e7 + 1;
int const Q = 1e6 + 1;

int sUb;
int n, q, MOD;
int arr[N];

// ll phi(ll x){
// 	ll ans = x;
// 	for (ll i = 2; i * i <= x; i++) if (x % i == 0){
// 		while (x % i == 0) x /= i;
// 		ans -= ans / i;
// 	}
// 	if (x > 1)
// 		ans -= ans / x;
// 	return ans;
// }

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % MOD * (x % MOD) % MOD;
	return 1LL * ans * ans % MOD;
}

// int const V = 1e7 + 1;
// vector<int> primes;

// void init(){
// 	vector<bool> sang(v, 0);
// 	sang[1] = sang[0] = 1;
// 	for (ll i = 1; i < v; i++) if (!sang[i]){
// 		for (ll j = i * i; j < v; j += i) sang[j] = 1;
// 		primes.push_back(i);
// 	}
// }

// namespace sub1{
// 	void solve(){
// 		while (q--){
// 			int l, r; cin >> l >> r;
// 			set<int> p;
// 			ll ans = 1;
// 			for (int i = l; i <= r; i++){
// 				ll x = arr[i];
// 				for (ll j = 2; j * j <= x; j++) if (x % j == 0){
// 					while (x % j == 0) x /= j;
// 					p.insert(j);
// 				}
// 				if (x > 1) p.insert(x);
// 				ans = ans * arr[i] % MOD;
// 			} 

// 			for (int x: p)
// 				ans = (ans - ans * mpow(x, MOD - 2) % MOD + MOD) % MOD;
			
// 			cout << ans << " ";
// 		}
// 	}
// }//co the tinh = cach xai res[l][r]

// namespace sub2{
// 	int const V = 1e7 + 1;
// 	void solve(){
// 		int vis[V] = {}, id = 0;
// 		while (q--){
// 			id++;
// 			int l, r; cin >> l >> r;
			
// 			vector<int> p;
// 			ll ans = 1;
// 			for (int i = l; i <= r; i++){
// 				ll x = arr[i], y = arr[i];
// 				for (ll j = 2; j * j <= x; j++) if (x % j == 0){
// 					while (x % j == 0) x /= j;
// 					if (vis[j] != id){
// 						vis[j] = id;
// 						y /= j;
// 						p.push_back(j);
// 					}
// 				}
// 				if (x > 1){
// 					if (vis[x] != id){
// 						vis[x] = id;
// 						y /= x;
// 						p.push_back(x);
// 					}
// 				}
// 				ans = ans * (y % MOD) % MOD;
// 			} 

// 			for (int x: p)
// 				ans = ans * ((x % MOD - 1 + MOD) % MOD) % MOD;
			
// 			cout << ans << " ";
// 		}
// 	}
// }

// namespace sub3{
// 	int const V = 21;
// 	vector<int> primes;

// 	void init(){
// 		bool sang[V] = {};
// 		sang[1] = sang[0] = 1;
// 		for (ll i = 1; i < V; i++) if (!sang[i]){
// 			for (ll j = i * i; j < V; j += i) sang[j] = 1;
// 			primes.push_back(i);
// 		}
// 	}

// 	int mem[21];
// 	ll funnypow(ll x, ll n){
// 		if (n == MOD - 2 && mem[x] != -1) return mem[x];
// 		if (n == 0) return 1;
// 		ll ans = mpow(x, n / 2);
// 		if (n & 1) return mem[x] = ans * ans % MOD * (x % MOD) % MOD;
// 		return mem[x] = ans * ans % MOD;
// 	}
// 	int cnt[N][21]; ll pre[N] = {1};
// 	void solve(){
// 		init();
// 		memset(mem, -1, sizeof mem);

// 		for (int i = 1; i <= n; i++){
// 			for (auto x: primes){
// 				cnt[i][x] += (arr[i] % x == 0);
// 				cnt[i][x] += cnt[i - 1][x];
// 			}

// 			pre[i] = pre[i - 1] * (arr[i] % MOD) % MOD;
// 		}


// 		while (q--){
// 			int l, r; cin >> l >> r;
// 			ll ans = pre[r] * mpow(pre[l - 1], MOD - 2) % MOD;
// 			for (auto x: primes){
// 				if (cnt[r][x] - cnt[l - 1][x])
// 					ans = (ans - ans * funnypow(x, MOD - 2) % MOD + MOD) % MOD;
// 			}	
// 			cout << ans << " ";
// 		}
// 	}
// }

// namespace sub4{
// 	int const V = 21;
// 	vector<int> primes;

// 	void init(){
// 		bool sang[V] = {};
// 		sang[1] = sang[0] = 1;
// 		for (ll i = 1; i < V; i++) if (!sang[i]){
// 			for (ll j = i * i; j < V; j += i) sang[j] = 1;
// 			primes.push_back(i);
// 		}
// 		debug(primes.size());
// 	}
// 	int cnt[N][9];
// 	int cntc(int x, int p){
// 		int ans = 0;
// 		while (x % p == 0) ans ++, x /= p;
// 		return ans;
// 	}
// 	void solve(){
// 		init();

// 		for (int i = 1; i <= n; i++){
// 			for (int j = 0; j < primes.size(); j++){
// 				cnt[i][j] += cntc(arr[i], primes[j]);
// 				cnt[i][j] += cnt[i - 1][j];
// 			}
// 		}

// 		while (q--){
// 			int l, r; cin >> l >> r;
// 			int ans = 1;
// 			for (int j = 0; j < primes.size(); j++){
// 				int c = cnt[r][j] - cnt[l - 1][j];
// 				if (c){
// 					// debug(primes[j], c);
// 					ans = 1LL * ans * mpow(primes[j], c - 1) % MOD * ((primes[j] % MOD - 1 + MOD) % MOD) % MOD;
// 				}
// 			}	
// 			cout << ans << " ";
// 		}
// 	}
// }

namespace sub6{
	// int const N = 1e5 + 1;
	// int const V = 1e5 + 1;
	int lcp[V], ans[Q], last[V];
	vector<pair<int, int> > queries[N];
	void init(){
		for (int i = 2; i * i < V; i++) if (!lcp[i]){
			for (int j = i * i; j < V; j += i) if (!lcp[j])
				lcp[j] = i;
		}
		for (int i = 2; i < V; i++) if (!lcp[i])
			lcp[i] = i;
	} 
	int lz[N << 2];
	void upd(int L, int R, int val, int x = 1, int l = 1, int r = n){
		if (r < L || R < l) return;
		if (L <= l && r <= R){
			lz[x] = 1LL * lz[x] * (val % MOD) % MOD;
			return;
		}
		int mid = (l + r) >> 1;
		upd(L, R, val, 2 * x, l, mid);
		upd(L, R, val, 2 * x + 1, mid + 1, r);
	}
	int get(int p){
		int x = 1, l = 1, r = n;
		int ans = 1;
		while (true){
			ans = 1LL * ans * lz[x] % MOD;
			int mid = (l + r) >> 1;
			if (l == r) return ans;
			if (p <= mid){
				x *= 2, r = mid;
			}else x = 2 * x + 1, l = mid + 1;
		}
	}

	void solve(){
		init();
		for (int i = 1; i <= q; i++){
			int l, r; cin >> l >> r;
			queries[l].push_back({r, i});
		}

		for (int i = 0; i < V; i++) last[i] = n + 1;

		for (int i = 0; i < 4 * N; i++)
			lz[i] = 1;

		for (int l = n; l >= 1; l--){
			int tmp = arr[l];
			while (tmp > 1){
				int p = lcp[tmp], k = 0;
				while (tmp % p == 0) tmp /= p, k++;
				upd(l, last[p] - 1, (p % MOD - 1 + MOD) % MOD * mpow(p, k - 1) % MOD);
				upd(last[p], n, mpow(p, k));
				last[p] = l;
			}
			for (int i = 0; i < queries[l].size(); i++)
				ans[queries[l][i].second] = get(queries[l][i].first);
		}

		for (int i = 1; i <= q; i++)
			cout << ans[i] << " ";
	}



}

#define file "req"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> sUb;
	cin >> n >> q >> MOD;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	// if (sUb == 1) sub1::solve();
	// if (sUb == 2) sub2::solve();
	// if (sUb == 3) sub3::solve();
	// if (sUb == 4) sub4::solve();
	// if (sUb == 6)
		sub6::solve();
	// debug(phi(9 * 9 * 7));
	return 0;
}
