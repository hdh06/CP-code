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
#define file "BUS"

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

struct edge{
	int a, b, w;
	edge(){}
	edge(int a, int b, int w): a(a), b(b), w(w){}
};

int n, m, s, t;
vector<edge> A, B;

struct dsu{
	int lk[N];
	void reset(int n){
		iota(lk + 1, lk + n + 1, 1);
	}
	int find(int v){return lk[v] = lk[v] == v? v: find(lk[v]);}
	bool unite(int a, int b){
		a = find(a), b = find(b);
		if (a == b) return false;
		lk[b] = a;
		return true;
	}
};

dsu d1, d2;

bool cmp(edge x, edge y){return x.w < y.w;}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++){
		int c, a, b, w; cin >> c >> a >> b >> w;
		if (c == 1) A.pb(edge(a, b, w));
		else B.pb(edge(a, b, w));
	}

	sort(all(A), cmp);
	sort(all(B), cmp);

	d1.reset(n);

	int ans = INT_MAX;
	for (auto eA: A){
		d1.unite(eA.a, eA.b);
		if (d1.find(s) == d1.find(t)){
			cout << eA.w << "\n";
			return 0;
		}
		for (int i = 1; i <= n; i++) d2.lk[i] = d1.lk[i];
		int j = 0;
		while (j < B.size() && d2.find(s) != d2.find(t)){
			d2.unite(B[j].a, B[j].b);
			j++;
		}
		j--;
		ans = min(ans, eA.w + B[j].w);
	}	

	cout << ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!