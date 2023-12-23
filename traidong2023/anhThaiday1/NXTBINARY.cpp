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

int n, a, b;
string s;

namespace sub1{
	void solve(){
		vi z;
		for (int mask = 0; mask < (1 << n); mask++){
			bool y = 1;
			for (int i = 0; i < n - 1; i++) if ((mask &(1 << i)) && (mask & (1 << (i + 1))))
				y = 0;
			if (y) z.pb(mask);
		}
		sort(all(z));
		
		ll fa = 1, fb = 1, fc = 1;
		for (int i = 2; i <= a; i++){
			fc = (fa + fb) % z.size();
			fa = fb;
			fb = fc;
		}
		
		int k = (fc + b) % z.size();
		
		int x = 0;
		for (int i = 0; i < n; i++) x = 2 * x + (s[i] == '1');
		int pos = 0;
		while (z[pos] != x) pos++;
		x = z[(pos + k) % z.size()];
		// debug(x);
		string f;
		for (int i = 0; i < n; i++){
			f.pb(x % 2 + '0');
			x /= 2;
		}
		reverse(all(f));
		cout << f;
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> a >> b;
	cin >> s;
	
	sub1::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!