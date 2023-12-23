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

bool const SINGLE_TEST = 1;

struct P{
	ll x, y;
	P() {}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){
		return sqrtl(x * x + y * y);
	}
};

double angle(P A){
	if (A.y < 0) return 8 * atan(1) - acos(A.x / A.dis());
	return acos(A.x / A.dis());
}

void print(__int128 x){
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

void solve(){	
	int n; cin >> n;
	vector<P> arr;
	__int128 X = 0, Y = 0;
	for (int i = 1; i <= n; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int x = a - b;
		int y = c - d;
		
		if (x != 0 || y != 0){
			arr.pb(P(x, y));
			arr.pb(P(-x, -y));
		}
		
		if (y < 0 || (y == 0 && x < 0))
			X += x, Y += y;
	}
	
	sort(all(arr), [](P A, P B){
		return angle(A) < angle(B);
	});
	
	__int128 ans = X * X + Y * Y;
	for (auto p: arr){
		X += p.x, Y += p.y;
		ans = max(ans, X * X + Y * Y);
	}
	
	print(ans);
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