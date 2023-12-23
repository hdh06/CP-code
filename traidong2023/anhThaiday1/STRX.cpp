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
#define file "flie"

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

int const N = 5001;

string OR(string a, string b){
	string c(a.size(), '0');
	for (int i = 0; i < a.size(); i++)
		if (a[i] == '1' || b[i] == '1') c[i] = '1';
	return c;
}

bitset<N> sf[N];
bitset<N> ans;

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	
	string t, s; cin >> t >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
	 	ans[i] = t[i] - '0';
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) sf[i][j] = s[j] - '0';
		rotate(s.begin(), s.begin() + 1, s.end());
	}
	
	// if (n <= 500) 
	for (int i = 0; i < n; i++) if ((sf[i] | ans) == ans)
		for (int j = i; j < n; j++) if ((sf[i] | sf[j]) == ans){
			cout << i << " " << j << "\n";
			return 0;
		}
	cout << -1;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!