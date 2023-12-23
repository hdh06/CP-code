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
	string s; cin >> s;
	int sz = s.size();
	for (int i = 0, j = sz - 1; i <= j; i++, j--){
		if (s[i] == s[j] && s[i] != 'a'){
			s.insert(i, "a");
			break;
		}
	}
	
	bool flag = 1;
	for (auto x: s) if (x != 'a') flag = 0;
	
	if (s.size() == sz){
		s.insert(sz / 2, "a");
	}
	if (!flag){
		cout << "YES\n";
		cout << s << "\n";
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