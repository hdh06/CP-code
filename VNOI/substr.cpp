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

int const N = 1e6 + 1;
int const A = 1e9 + 7, MOD = 1e9 + 9;

struct hat{ // a.k.a hash but hat
	int a = 0; ll b = 0;
	hat(){}
	hat(int a, ll b):a(a), b(b) {}
	bool isE(hat z){
		return a == z.a && b == z.b;
	}
};

pair<int, ll> powA[N];
void init(){
	powA[0] = mp(1, 1);
	for (int i = 1; i < N; i++)
		powA[i] = mp(1LL * powA[i - 1].st * A % MOD, powA[i - 1].nd * A);
}

int n;
string s, p;
hat h[N];

hat get(int l, int r){
	return hat((h[r].a - 1LL * (l >= 1? h[l - 1].a: 0) * powA[r - l + 1].st % MOD + MOD) % MOD, h[r].b - (l >= 1? h[l - 1].b: 0) * powA[r - l + 1].nd);
}

void solve(){	
	init();
	cin >> s >> p;
	n = s.size();
	h[0] = hat(s[0], s[0]);
	for (int i = 1; i < n; i++){
		h[i].a = 1LL * h[i - 1].a * A % MOD + s[i]; if (h[i].a >= MOD) h[i].a -= MOD;
		h[i].b = h[i - 1].b * A + s[i];
	}
		
	hat phat;
	for (int i = 0; i < p.size(); i++){
		phat.a = 1LL * phat.a * A % MOD + p[i]; if (phat.a >= MOD) phat.a -= MOD;
		phat.b = phat.b * A + p[i];
	}
	// cerr << phat.a << ' ' << phat.b << "\n";
	
	for (int i = 0; i + p.size() - 1 < n; i++)
		if (get(i, i + p.size() - 1).isE(phat)) cout << i + 1 << " ";
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