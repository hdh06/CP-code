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
#define file "rotgame"

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

struct query{
	int t, x;
	query(){}
	void read(){cin >> t >> x;}
};

int const N = 1e5 + 1;

int n, k, q;
query queries[N];
int z[N];

namespace sub1{
	int p[N], b[N];
	void solve(){
		for (int i = 0; i < n; i++)
			p[i] = i;
			
		
		for (int i = 1; i <= q; i++){
			swap(b, p);
			if (queries[i].t == 1){
				for (int j = 0; j < n; j++){
					int x = j + queries[i].x;
					if (x >= (j / k + 1) * k) x -= k;
					if (x < j / k * k) x += k;
					p[x] = b[j];
				}
			}
			if (queries[i].t == 2){
				for (int j = 0; j < n; j++){
					int x = j + queries[i].x;
					if (x >= n) x -= n;
					if (x < 0) x += n;
					p[x] = b[j];
				}
			}
		// debug(queries[i].x);
		// debug(vi(p, p + n));
		}
		
		int ans[N];
		for (int i = 0; i < n; i++)
			ans[p[i]] = z[i];
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> n >> k >> q;
	for (int i = 1; i <= q; i++){
		queries[i].read();
		int sign = queries[i].x >= 0;
		if (queries[i].t == 1)
			queries[i].x = (sign? 1: -1) * (abs(queries[i].x) % k);			
			
		if (queries[i].t == 2)
			queries[i].x = (sign? 1: -1) * (abs(queries[i].x) % n);
	}
	for (int i = 0; i < n; i++)
		cin >> z[i];
	
	if (n <= 100)
		sub1::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!