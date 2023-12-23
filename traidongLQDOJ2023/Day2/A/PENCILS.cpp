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
#define file "PENCILS"

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

struct pen{
	int r, g, b;
	pen(){}
	pen(int r, int g, int b):r(r), g(g), b(b) {}
	void read(){cin >> r >> g >> b;}
};

int n, k;
pen pens[N];

namespace sub1{
	void solve(){
		int ans = INT_MAX, ans_mask = -1;
		for (int mask = 0; mask < (1 << n); mask++){
			if (__builtin_popcount(mask) != k) continue;
			pen maxx(0, 0, 0), minn(INT_MAX, INT_MAX, INT_MAX);
			for (int i = 0; i < n; i++) if (mask & (1 << i)){
				maxx.r = max(maxx.r, pens[i + 1].r);
				maxx.g = max(maxx.g, pens[i + 1].g);
				maxx.b = max(maxx.b, pens[i + 1].b);

				minn.r = min(minn.r, pens[i + 1].r);
				minn.g = min(minn.g, pens[i + 1].g);
				minn.b = min(minn.b, pens[i + 1].b);
			}
			int max_diff = 0;
			max_diff = max(max_diff, maxx.r - minn.r);
			max_diff = max(max_diff, maxx.g - minn.g);
			max_diff = max(max_diff, maxx.b - minn.b);

			if (ans > max_diff){
				ans = max_diff;
				ans_mask = mask;
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++) if (ans_mask & (1 << i))
			cout << pens[i + 1].r << " " << pens[i + 1].g << " " << pens[i + 1].b << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) pens[i].read();

	// if (n <= 20)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!