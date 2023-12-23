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
		
	int pre = -1, prepos = -1;
	int sum = 0;
	int t = 1;
	vi z(s.size(), 0);
	
	for (int i = 0; i < n; i++){
		sum += (s[i] == '(' ? 1 : -1);
		if (sum < 0) t = 0;
		if (sum == 0){
			if (t != pre){
				z[prepos + 1] = t + 1;
				pre = t;
			}
			prepos = i;
			t = 1;
		}
	}
	
	if (sum != 0){
		cout << "-1\n";
		return;
	}
	
	int ans = 0;
	for (auto x: z){
		if (x == 1) ans |= 1;
		if (x == 2) ans |= 2;
	}
	ans = __builtin_popcount(ans);
	
	cout << ans << "\n";
	int d = 0;
	for (int i = 0; i < n; i++){
		if (z[i]) d = z[i];
		cout << d - (ans == 1 && d == 2) << " ";
	}
	debug(z);
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
}//it's coding time!