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
#define file "verify"

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

struct query{
	int l, r, a;
	query(){}
	query(int l, int r, int a):l(l), r(r), a(a) {}
	
	void read(){cin >> l >> r >> a;}
};

int n, q;
query queries[N];

namespace sub3{
	int tree[N << 2];
	int lz[N << 2];
	
	void down(int x){
		if (lz[x]){
			tree[2 * x] = tree[2 * x + 1] = -1;
			lz[2 * x] = lz[2 * x + 1] += lz[x];
			
		}
	}
	
	
	void solve(){
		for (int i = 1; i <= q; i++){
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n >> q;
	for (int i = 1; i <= q; i++) queries[i].read();
	
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!