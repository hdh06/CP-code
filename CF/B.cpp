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
	vector<ii> z;
	for (ll i = 2; i * i <= n; i++){
		if (n % i == 0){
			int cnt = 0;
			while (n % i == 0) n /= i, cnt++;
			z.pb({cnt, i});
		}	
	}
	if (n > 1) z.pb({1, n});
	
	sort(all(z));
		
	int t = 1;
	for (auto x: z) t *= x.nd;
	
	int last = 0;
	int ans = 0;
	for (int i = 0; i < z.size(); i++){
		ans += t * (z[i].st - last);
		t /= z[i].nd;
		last = z[i].st;
	}
	cout << ans << "\n";
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