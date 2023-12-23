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
#define file "palival"

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

vector<int> manacher_odd(string s){
	s = '$' + s; s = s + '%';
	int n = s.size();
	vector<int> p(n, 0);
	for (int i = 1, l = 0, r = 0; i < n - 1; i++){
		p[i] = max(0, min(r - i, p[l + r - i]));
		while (s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (i + p[i] > r) r = i + p[i], l = i - p[i];
	}
	return vector<int>(p.begin() + 1, p.end() - 1);
}

string s;

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> s;
	
	string t;
	for (auto x: s){
		t.pb(x);
		t.pb('#');
	}
	t.erase(t.size() - 1, 1);
	
	vi z = manacher_odd(t);
	
	ll ans = 0;
	for (auto x: z){
		ans += (x + 1) / 2;
	}
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!