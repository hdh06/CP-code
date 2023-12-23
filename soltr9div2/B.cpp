#include <bits/stdc++.h>

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
int const N = 2e5 + 1;
int n, k; 
string s;

void solve(){
	cin >> n >> k;
	cin >> s;
	
	int ans = INT_MAX;
	deque<int> c, t, l;
	for (int i = 0; i < n; i++){
		if (c.size() < k){
			if (s[i] == 'C') c.pb(i);
		}else{
			while (t.size() && t.front() < c.back()) t.pof();
			for (int j = (t.empty()?i: t.back() + 1); j < n && t.size() < k; j++)
				if (s[j] == 'T') t.pb(j);
			
			if (t.size() < k) break;
			
			while (l.size() && l.front() < t.back()) l.pof();
			for (int j = (l.empty()? t.back() + 1:l.back() + 1); j < n && l.size() < k; j++)
				if (s[j] == 'L') l.pb(j);
				
			if (c.size() == k && t.size() == k && l.size() == k)
				ans = min(ans, l.back() - c.front() + 1 - 3 * k);
			
			c.pof();
			if (s[i] == 'C')
				c.pb(i);
		}
	}
	
	cout << (ans == INT_MAX? -1: ans);
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