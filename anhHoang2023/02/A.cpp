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

int const N = 2e5 + 1;

int cnt[N];
int cntp[N];

void solve(){	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		cnt[x]++;
	}
		
	int rmd = 0, que = 0;	
	vi z;
	for (int i = 1; i <= m; i++){
		int x; cin >> x;
		cntp[x]++;
	}	

	for (int i = 1; i < N; i++){
		que += cntp[i];
		while (que && rmd){
			que--, rmd--;
			cout << i << " ";
		}
		if (que){
			vi p;
			for (ll j = 1; j * j <= i; j++) if (i % j == 0){
				p.pb(j);
				p.pb(i / j);
			}
			sort(all(p));
			for (auto j: p){
				if (cnt[j]){
					rmd += cnt[j];
					cnt[j] = 0;
				}
			}
		}
		
		while (que && rmd){
			que--, rmd--;
			cout << i << " ";
		}
	}
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