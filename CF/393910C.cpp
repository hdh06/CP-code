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

int const N = 4e5 + 1;

struct P{
	ll x, y;
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	ll dis2(){return x * x + y * y;}
	double dis(){return sqrt(x * x + y * y);}
};

P vtc(P A, P B){return {B.x - A.x, B.y - A.y};}
P pl(P A, P B){return {A.x + B.x, A.y + B.y};}
double angle(P A){
	if (A.y < 0) return 8 * atan(1) - acos(1.0L * A.x / A.dis());
	return acos(1.0L * A.x / A.dis());
}
double angle(P A, P B){
	if (angle(B) - angle(A) < 0)
		return angle(B) - angle(A) + 8.0L * atan(1);
	return angle(B) - angle(A); 
}

int n;
P arr[N];

void solve(){	
	cin >> n;
	P sum(0, 0);
	vector<P> arr;
	for (int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		if (x != 0 || y != 0){
			arr.pb(P(x, y));
			arr.pb(P(-x, -y));
		}
	
		if (y < 0 || (y == 0 && x < 0))
			sum = pl(sum, P(x, y));
	}
	
	sort(all(arr), [](P A, P B){
		return angle(A) < angle(B);
	});
	
	ll ans = sum.dis2();
	for (auto x: arr){
		sum = pl(sum, x);
		ans = max(ans, sum.dis2());
	}

	cout << ans << "\n";
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