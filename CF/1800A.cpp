#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int i = 0, cnt = 0;
	cnt = 0;
	while (i < s.size() && (s[i] == 'm' || s[i] == 'M')) i++, cnt++;
	if (!cnt){cout << "NO\n";return;}
	cnt = 0;
	while (i < s.size() && (s[i] == 'e' || s[i] == 'E')) i++, cnt++;
	if (!cnt){cout << "NO\n";return;}
	cnt = 0;
	while (i < s.size() && (s[i] == 'o' || s[i] == 'O')) i++, cnt++;
	if (!cnt){cout << "NO\n";return;}
	cnt = 0;
	while (i < s.size() && (s[i] == 'w' || s[i] == 'W')) i++, cnt++;
	if (!cnt){cout << "NO\n";return;}
	
	if (i == s.size()){
		cout << "YES\n";
	}else cout << "NO\n";
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
}//it's coding time!