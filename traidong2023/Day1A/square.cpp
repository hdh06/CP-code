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
#define file "square"

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

int const N = 56 + 1;

int n;
char arr[N][N];
int col[N];
int row[N];

void solve(){
	cin >> n;
	memset(col, 0, sizeof col);
	memset(row, 0, sizeof row);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'X') col[j] ++;
			if (arr[i][j] == 'X') row[i] ++;
		}			

	set<int> R(row + 1, row + n + 1);
	set<int> C(col + 1, col + n + 1);
	
	vi r(all(R)), c(all(C));
	vi tmp = {1, 2};
	if (r == tmp && c == tmp){
		cout << "POSSIBLE\n";
	}else cout << "IMPOSSIBLE\n";
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	int t; cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!