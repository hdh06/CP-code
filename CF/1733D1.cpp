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
	int n; ll x, y; cin >> n >> x >> y;
	string a, b; cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) cnt++;
	if (cnt & 1){
		cout << "-1\n";
		return;
	}

	ll ans = (cnt / 4) * y * 2;
	cnt %= 4;
	if (cnt == 2){
		bool flag = 0;
		for (int i = 1; i <= n; i++) if (!flag)
			for (int j = i + 2; j <= n; j++){
				if (a[i] != b[i] && a[j] != b[j]){
					ans += y;
					flag = 1;
					break;
				}
			}
		if (!flag) ans += min(x, 2 * y);
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