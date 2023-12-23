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
#define file "fiel"

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

bool const SINGLE_TEST = 0;

ll dis(pll a, pll b){return abs(a.st - b.st) + abs(a.nd - b.nd);}

void solve(){	
	int n, k, a, b; cin >> n >> k >> a >> b;
	
	vll arr(n + 1);
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i].st >> arr[i].nd;
	
	ll disA =  1e11, disB = 1e11;
	for (int i = 1; i <= k; i++) {
		disA = min(disA, dis(arr[a], arr[i]));
		disB = min(disB, dis(arr[b], arr[i]));
	}
	
	cout << min(dis(arr[a], arr[b]), disA + disB) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!