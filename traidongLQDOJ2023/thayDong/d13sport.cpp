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

int const N = 1e5 + 1;

int n;
int a[N], b[N];

namespace sub1{
	void solve(){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) if (i != j)
				for (int x = 1; x <= n; x++)
					for (int y = 1; y <= n; y++) if (x != y)
						if (abs(a[i] - b[y]) >= min(abs(a[i] - b[x]), abs(a[j] - b[y]))){
							cout << i << " " << x << "\n";
							cout << j << " " << y << "\n";
							
							int d = 1;
							for (int u = 1; u <= n; u++) if (u != i && u != j){
								while (d == x || d == y) d++;
								cout << u << " " << d << "\n";
 							}
							return;
						}
						
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	// if (n <= 10)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!