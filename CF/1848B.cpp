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
	int n, k; cin >> n >> k;
	vi m1(k + 1, 0), m2(k + 1, 0), pre(k + 1, 0);
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (m1[x] < i - pre[x] - 1){
			m2[x] = m1[x];
			m1[x] = i - pre[x] - 1;
		}else if (m2[x] < i - pre[x] - 1) m2[x] = i - pre[x] - 1;
		pre[x] = i;
	}
	
	for (int x = 1; x <= k; x++){
		if (m1[x] < n - pre[x]){
			m2[x] = m1[x];
			m1[x] = n - pre[x];
		}else if (m2[x] < n - pre[x]) m2[x] = n - pre[x];
	}
		
	int ans = INT_MAX;
	for (int x = 1; x <= k; x++){
		ans = min(ans, max(m1[x] / 2, m2[x]));
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