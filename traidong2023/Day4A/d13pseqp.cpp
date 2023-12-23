#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "flie"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const N = 1e5 + 1;

int n, q;
int a[N];
int b[N];

ii queries[N];

namespace sub1{
	void solve(){
		for (int i = 1; i <= q; i++){
			swap(b[queries[i].st], b[queries[i].nd]);
			
			int ans = 0;
			for (int j = 1; j <= n; j++){
				int cnt = 0;
				rotate(a + 1, a + 2, a + n + 1);
				for (int k = 1; k <= n; k++)
					cnt += (a[k] == b[k]);
				ans = max(ans, cnt);
			}
			
			cout << ans << "\n";
		}	
	}
}
namespace sub2{	
	int posA[N], posB[N];
	int cnt[N];
	int sif(int x){
		int d = posB[b[x]] - posA[b[x]];
		if (d < 0) return d + n;
		return d;
	}
	void solve(){
		for (int i = 1; i <= n; i++)
			posA[a[i]] = i, posB[b[i]] = i;
		
		for (int i = 1; i <= n; i++)
			cnt[sif(i)]++;
		
		for (int i = 1; i <= q; i++){
			int x = queries[i].st, y = queries[i].nd;

			cnt[sif(x)]--;
			cnt[sif(y)]--;
			swap(posB[b[x]], posB[b[y]]);
			swap(b[x], b[y]);
			cnt[sif(x)]++;
			cnt[sif(y)]++;
			int ans = 0;
			for (int i = 0; i <= n; i++) 
				ans = max(ans, cnt[i]);
			cout << ans << "\n";
		}
	}
}

namespace sub3{	
	int posA[N], posB[N];
	
	int tree[N << 2];
	void upd(int pos, int val, int x = 1, int l = 0, int r = n - 1){
		if (r < pos || pos < l) return;
		if (l == r){
			tree[x] += val;
			return;
		}
		
		int mid = (l + r) >> 1;
		upd(pos, val, 2 * x, l, mid);
		upd(pos, val, 2 * x + 1, mid + 1, r);
		tree[x] = max(tree[2 * x], tree[2 * x + 1]);
	}
	
	int sif(int x){
		int d = posB[b[x]] - posA[b[x]];
		if (d < 0) return d + n;
		return d;
	}
	void solve(){
		for (int i = 1; i <= n; i++)
			posA[a[i]] = i, posB[b[i]] = i;
		
		for (int i = 1; i <= n; i++)
			upd(sif(i), 1);
		
		for (int i = 1; i <= q; i++){
			int x = queries[i].st, y = queries[i].nd;

			upd(sif(x), -1);
			upd(sif(y), -1);
			swap(posB[b[x]], posB[b[y]]);
			swap(b[x], b[y]);
			upd(sif(x), +1);
			upd(sif(y), +1);

			cout << tree[1] << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= q; i++)
		cin >> queries[i].st >> queries[i].nd;
		
	if (n <= 100 && q <= 100)
		sub1::solve();
	else if (n <= 100000 && q <= 100)
		sub2::solve();
	else
		sub3::solve();
	
		
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!