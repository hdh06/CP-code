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
#define file "OXBET"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
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

typedef pair<db, db> dd;

int n;
double a[N], b[N];

namespace sub1{
	void maximize(dd &x, dd v){
		if (min(x.st, x.nd) < min(v.st, v.nd)) x = v;
	}

	dd dp[N];
	dd calc(int i){
		if (i == n + 1) return mp(0.0, 0.0);

		dd &ans = dp[i];
		if (ans.st != -1.0) return ans;
		dd p = calc(i + 1);
		ans = p;
		maximize(ans, mp(p.st + a[i] - 1, p.nd - 1));
		maximize(ans, mp(p.st - 1, p.nd + b[i] - 1));
		return ans;
	}
	void solve(){
		for (int i = 0; i < N; i++) dp[i] = mp(-1.0, -1.0);

		dd p = calc(1);
		cout << setprecision(4) << fixed << min(p.st, p.nd);
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!