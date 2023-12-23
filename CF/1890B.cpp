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

void solve(){	
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	bool fl = 1;
	for (int i = 0; i < n - 1; i++) if (s[i] == s[i + 1]) fl = 0;
	if (fl){
		cout << "Yes\n";
		return;
	}
	
	bool fl2 = 1;
	if (t.size() % 2 == 0){
		cout << "No\n";
		return;
	} 
	
	bool A = 0, B = 0;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1]){
			if (s[i] == '1') A = 1;
			if (s[i] == '0') B = 1;
		}
		
	for (int i = 0; i < m - 1; i++) 
		if (t[i] == t[i + 1]) 
			fl2 = 0;
		
	if (!fl2){
		cout << "No\n";
	}else{
		if (A && t[0] != '0'){
			cout << "No\n";
			return;
		}
		if (B && t[0] != '1'){
			cout << "No\n";
			return;
		}
		// debug(n, m, A, B);
		cout << "Yes\n";
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