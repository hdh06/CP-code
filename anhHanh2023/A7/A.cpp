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
#define file "ADN"

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

string z = "ATGC";

bool calc(string &t, string s, int k){
	if (k == 0)  debug(t, s);
	if (k == 0){
		return t == s;
	}
	
	int n = s.size();
	
	bool ans = 0;
	for (int i = 0; i <= n; i++)
		for (char x: z){
			string r = s;
			r.insert(i, string(1, x));
			ans |= calc(t, r, k - 1);
		}
	
	for (int i = 0; i < n; i++)
		for (char x: z){
			string r = s;
			r[i] = x;
			ans |= calc(t, r, k - 1);
		}
	
	for (int i = 0; i < n; i++){
		string r = s;
		r.erase(i, 1);
		ans |= calc(t, r, k - 1);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	string a, b; cin >> a >> b;
	
	cout << (calc(b, a, 2)? "Yes": "No");
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!