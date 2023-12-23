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

int const N = 51;

struct worm{
	ll a, b, c, d;
	worm(){}
	worm(ll a, ll b, ll c, ll d): a(a), b(b), c(c), d(d) {}
	void read(){cin >> a >> b >> c >> d;}
};

struct P{
	ll x, y;
	
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){return sqrt(x * x + y * y);}
	ll dis2(){return x * x + y * y;}
	ll dot(P A){return x * A.x + y * A.y;}
	ll cross(P A){return x * A.y - y * A.x;}
	double angle(){return y >= 0? acos(x / dis()): 8 * atan(1) - acos(x / dis());}
	double angle(P A){return acos(dot(A) / dis() / A.dis());}
	P operator -(P A){return P(x - A.x, y - A.y);}
	P operator +(P A){return P(x + A.x, y + A.y);}
	P operator *(ll v){return P(x * v, y * v);}
	P operator /(ll v){assert(v != 0);return P(x / v, y / v);}
	
	void read(){cin >> x >> y;}
	void flip90cw(){x = -x, swap(x, y);}
	void flip90cww(){y = -y, swap(x, y);}
	void flip180(){x = -x, y = -y;}
};


int n, T;
worm worms[N];
P arr[N];
int ccw(P A, P B, P C){
	ll crs = (B - A).cross(C - B);
	if (crs == 0) return 0;
	if (crs < 0) return -1;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	cin >> n >> T;
	for (int i = 1; i <= n; i++)	
		worms[i].read();

	// sort(worms + 1, worms + n + 1, [](worm x, worm y){
		// if (x.a + x.b == y.a + y.b) return x.c + x.d < y.c + y.d;
		// return x.a + x.b < y.a + y.b;
	// });
// 	
	ll ans = 0;
	for (int t = 1; t <= T; t++){
		for (int k = 1; k <= n; k++)
			arr[k] = P(worms[k].a * t + worms[k].b, worms[k].c * t + worms[k].d);
	
		sort(arr + 1, arr + n + 1, [](P a, P b){
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		});
	
		vector<P> st;
		for (int z = 1; z <= 2; z++){
			int start = st.size();
			for (int k = 1; k <= n; k++){
				while (st.size() >= start + 2 && ccw(st[st.size() - 2], st.back(), arr[k]) > 0)
					st.pob();
				st.pb(arr[k]);
			}
			if (z == 1) st.pob();
			reverse(arr + 1, arr + n + 1);
		}
		
		ll sum = 0;
		for (int k = 0; k < st.size() - 1; k++)
			sum += (arr[k].x - arr[k + 1].x) * (arr[k].y + arr[k + 1].y);
		ans += abs(sum);
	}
	cout << 0.5L * ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!