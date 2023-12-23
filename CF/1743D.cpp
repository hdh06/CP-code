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

bool const SINGLE_TEST = 1;

string Sor(string a, string b){
	reverse(all(a));
	reverse(all(b));
	if (b.size() > a.size()) swap(a, b);
	for (int i = 0; i < b.size(); i++)
		if (b[i] == '1') a[i] = '1';
	reverse(all(a));
	return a;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int i = 0;
	while (i < n && s[i] == '0') i++;
	int j = i;
	while (j < n && s[j] == '1') j++;
	if (i == n || j == n){
		while (s.size() > 1 && s[0] == '0') s.erase(0, 1);
		cout << s;
		return;
	}
	
	string ans(n, '0');
	for (int k = i; k < j; k++)
		ans = max(ans, Sor(s, s.substr(k, n - j)));
	
	while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
	cout << ans;
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