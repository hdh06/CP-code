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

int n, k;
int arr[N];

double psum[N];

bool f(double a){
	for (int i = 1; i <= n; i++)
		psum[i] = psum[i - 1] + arr[i] - a;
			
	double minn = 0;
	int j = 0;
	for (int i = k; i <= n; i++){
		while (i - j > k) minn = min(minn, psum[++j]);
		if (psum[i] >= minn) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	double ans = -1;
	double l = -1e5, r = 1e5;
	for (int i = 1; i <= 100 && l <= r; i++){
		double mid = (l + r) * 0.5L;
		if (f(mid)){
			ans = mid;
			l = mid;
		}else r = mid;
	}
		
	cout << setprecision(5) << fixed << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!