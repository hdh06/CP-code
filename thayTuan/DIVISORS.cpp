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
#define file "DIVISORS"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 50001;
int const MOD = 1e9 + 7;

int arr[N];

vi primes;
map<int, int> id;
void init(){
	int const N = 10001;
	int sang[N] = {};
	for (int i = 2; i < N; i++) if (!sang[i])
		for (int j = i * i; j < N; j += i)
			sang[j] = 1;
	for (int i = 2; i < N; i++)
		if (!sang[i])
			primes.pb(i);
	for (int i = 0; i < primes.size(); i++)
		id[primes[i]] = i;
}

int tree[2000][50001];
void upd(int x, int val, int tree[]){
	for (int i = x; i < N; i += i & -i)
		tree[i] += val;
}
int get(int x, int tree[]){
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i)
		ans += tree[i];
	return ans;
}

void solve(){
	init();
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		arr[i] = x;
 		for (int d = 2; d * d <= x; d++){
			if (x % d == 0){
				int cnt = 0;
				while (x % d == 0) x /= d, cnt++;
				upd(i, cnt, tree[id[d]]);
			}
		}
		if (x > 1) upd(i, 1, tree[id[x]]);
	}
	
	
	int q; cin >> q;
	while (q--){
		int t; cin >> t;
		if (t){
			int l, r; cin >> l >> r;
			int ans = 1;
			for (auto x: id)
				ans = 1LL * ans * (get(r, tree[x.nd]) - get(l - 1, tree[x.nd]) + 1) % MOD;
			
			cout << ans << "\n";
		}else{
			int p, x; cin >> p >> x;
			for (int d = 2; d * d <= arr[p]; d++){
				int cnt = 0;
				while (arr[p] % d == 0) arr[p] /= d, cnt++;
				if (cnt) upd(p, -cnt, tree[id[d]]);
			}
			if (arr[p] > 1) upd(p, -1, tree[id[arr[p]]]);
			arr[p] = x;
			for (int d = 2; d * d <= x; d++){
				int cnt = 0;
				while (x % d == 0) x /= d, cnt++;
				if (cnt) upd(p, cnt, tree[id[d]]);			
			}
			if (x > 1) upd(p, 1, tree[id[x]]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!