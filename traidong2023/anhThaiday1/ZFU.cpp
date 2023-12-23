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


vi zfunc(string s){
	int n = s.size(); 
	vi z(n, 0);

	for (int i = 1, x = 0, y = 0; i < n; i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) x = i, y = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	string s; cin >> s;
	vi z = zfunc(s);
	z[0] = s.size();
	for (int i = s.size() - 2; i >= 0; i--){
		z[i] = max(z[i], z[i + 1]);
	}
	int q; cin >> q;
	while (q--){
		int x; cin >> x;
		cout << z[x - 1] << "\n"; 
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!