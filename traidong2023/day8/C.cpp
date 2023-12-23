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
#define file "fields"

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

int r, l, b;
int x[N];

ll suf[N];
ll pre[N];

bool f(int mid){
	int L = (mid + 1) / 2;
	int R = mid - L;
	
	// debug(mid, L, R);
	for (int i = 1; i <= r; i++){
		if (i - L < 0 || i + R > r) continue;
		// ll z = 1LL * x[i] * L 
			// + (pre[i] - pre[i - L]) 
			// - (pre[i + R] - pre[i]) 
			// - 1LL * x[i] * R;
		// debug(i, z);
		// debug(x[i] * L);
		// debug(pre[i] - pre[i - L]);
		// debug(- (pre[i + R] - pre[i]));
		// debug(- x[i] * R);
		// cerr << "->" << z << "\n";
		if (1LL * x[i] * L + (pre[i] - pre[i - L]) - (pre[i + R] - pre[i]) - 1LL * x[i] * R <= b) return true;
		
		// debug(suf[i + R] - suf[i]);
	}
	
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	int sub; cin >> sub;
	cin >> r >> l >> b;
	for (int i = 1; i <= r; i++)
		cin >> x[i];
	sort(x + 1, x + r + 1);
	
	for (int i = 1; i <= r; i++)
		pre[i] = pre[i - 1] - x[i];
	// for (int i = r; i >= 1; i--)
		// suf[i] = suf[i + 1] + x[i];
		
	debug(vi(pre + 1, pre + r + 1));
	// debug(vi(suf + 1, suf + r + 1));
	
	int ans = 0;
	for (int l = 1, rr = r; l <= rr;){
		int mid = (l + rr) >> 1;
		if (f(mid)){
			ans = mid;
			l = mid + 1;
		}else rr = mid - 1;
	}
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!