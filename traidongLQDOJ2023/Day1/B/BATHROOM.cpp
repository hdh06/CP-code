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
#define file "BATHROOM"

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

int const N = 3e4 + 1;

int n, q;
char arr[4][N];

namespace sub1{
	int key(int i, int j){
		return (i - 1) * n + j;
	}
	void solve(){
		while (q--){
			int t; cin >> t;
			if (t == 1){
				int x, y; cin >> x >> y;
				if (arr[x][y] == '.') arr[x][y] = 'x';
				else arr[x][y] = '.';
			}
			if (t == 2){
				int a, b; cin >> a >> b;
				vii z;
				for (int i = 1; i <= 3; i++)
					for (int j = a; j <= b; j++) if (arr[i][j] == '.'){
						if (i + 1 <= 3 && arr[i + 1][j] == '.') z.pb(mp(key(i, j), key(i + 1, j)));
						if (j + 1 <= b && arr[i][j + 1] == '.') z.pb(mp(key(i, j), key(i, j + 1)));
					}
				// debug(z);
				ll ans = 0;
				for (int mask = 0; mask < (1 << z.size()); mask++){
					vb isMark(3 * n, 0);
					bool flag = 1;
					for (int i = 0; i < z.size(); i++) if (mask & (1 << i)){
						if (isMark[z[i].st] || isMark[z[i].nd]){
							flag = 0;
							break;
						}
						isMark[z[i].st] = isMark[z[i].nd] = 1;
					}
					ans += flag;
				}
				cout << ans << "\n";
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];

	// if (n <= 8 && q <= 8)
		sub1::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!