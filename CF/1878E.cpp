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

bool const SINGLE_TEST = 0;

int const N = 2e5 + 1;
int const L = 30;

int arr[N];
int suf[L][N];

void solve(){	
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < L; i++){
		suf[i][n + 1] = n + 1;
		for (int j = n; j >= 1; j--){
			if (arr[j] & (1 << i))
				suf[i][j] = suf[i][j + 1];
			else suf[i][j] = j;
		}
	}
	
	int q; cin >> q;
	while (q--){
		int l, k; cin >> l >> k;
		int r = n + 1;
		int rr = l;
		for (int i = L - 1; i >= 0; i--){
			if (k & (1 << i)){
				r = min(r, max(rr, suf[i][l]));
			}else{
				rr = max(rr, suf[i][l]);
			}
		}
		cout << (r - 1 < l? -1 : r - 1) << " "; 
	}	
	cout << "\n";
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