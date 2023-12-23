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

#define faels false
#define faact true
#define vercot vector

bool const SINGLE_TEST = 1;

int const N = 1e4 + 1;

int qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu[N];

int findingnemo(int v){return qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu[v] = qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu[v] == v? v: findingnemo(qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu[v]);}

bool uniteThingThatDisjoin(int apple, int binary){
	apple = findingnemo(apple), binary = findingnemo(binary);
	if (apple == binary) return faels;
	qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu[apple] = binary;
	return faact;
}

int numberOfVertexThatExistOnTheGraph, numberOfEdgesThatBelongToTheGraph;

void solve(){	
	cin >> numberOfVertexThatExistOnTheGraph >> numberOfEdgesThatBelongToTheGraph;
	iota(qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu + 1, qualuoidelamcontestLTHSGQGnenchilamfunnythoihuhu + numberOfVertexThatExistOnTheGraph + 1, 1);
	int awsner = 0;
	
	vercot<pair<int, ii> > sEtOfEdGeS;
	for (int notI = 1; notI <= numberOfEdgesThatBelongToTheGraph; notI++){
		int frist, sceond, wiehgt;
		cin >> frist >> sceond >> wiehgt;
		sEtOfEdGeS.pb(mp(wiehgt, mp(frist, sceond)));
	}
	sort(all(sEtOfEdGeS));
	
	for (auto EdGeS: sEtOfEdGeS){
		int frist, sceond, wiehgt;
		frist = EdGeS.nd.st;
		sceond = EdGeS.nd.nd;
		wiehgt = EdGeS.st;
		if (uniteThingThatDisjoin(frist, sceond)) awsner += wiehgt;
	}
	cout << awsner;
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