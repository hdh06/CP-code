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
#define file "distance5"

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
};

int sign(ll x){return (x == 0? 0: (x < 0? -1 : 1));}

bool isLineIntersect(P A, P B, P C, P D){
	ll ABxAC = sign((B - A).cross(C - A));
	ll ABxAD = sign((B - A).cross(D - A));
	ll CDxCA = sign((D - C).cross(A - C));
	ll CDxCB = sign((D - C).cross(B - C));
	
	if (ABxAC * ABxAD * CDxCA * CDxCB == 0){
		if (ABxAC == 0 && (C - A).dot(C - B) <= 0) return true;
		if (ABxAD == 0 && (D - A).dot(D - B) <= 0) return true;
		if (CDxCA == 0 && (A - C).dot(A - D) <= 0) return true;
		if (CDxCB == 0 && (B - C).dot(B - D) <= 0) return true;
		return false;
	}
	
	return ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0;
}

double disPtoS(P A, P B, P C){
	ll BAoBC = (A - B).dot(C - B);
	ll CAoCB = (A - C).dot(B - C);
	
	if (BAoBC >= 0 && CAoCB >= 0)
		return abs((A - B).cross(C - B)) / (C - B).dis();
	if (BAoBC < 0)
		return (A - B).dis();
	return (A - C).dis();
}

void solve(){	
	P A, B; A.read(), B.read();
	P C, D; C.read(), D.read();
	
	if (isLineIntersect(A, B, C, D))
		cout << 0;
	else{
		double ans = disPtoS(A, C, D);
		ans = min(ans, disPtoS(B, C, D));
		ans = min(ans, disPtoS(C, A, B));
		ans = min(ans, disPtoS(D, A, B));
		
		cout << setprecision(6) << fixed << ans;
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".in", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!