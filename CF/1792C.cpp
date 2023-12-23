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
	vi arr(n + 1);
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	int l = (n + 1) / 2, r = l + (n % 2 == 0);
	int pl = -1, pr = -1;
	for (int i = 1; i <= n; i++) if (arr[i] == l) pl = i;
	pr = pl + (n % 2 == 0);
	
	while (1){
		while (pl >= 1 && arr[pl] != l) pl--;
		while (pr <= n && arr[pr] != r) pr++;
		if (pl < 1 || pr > n) break;
		if (arr[pl] == l && arr[pr] == r){
			pl--, pr++;
			l--, r++;
		}
	}
	
	if (arr[1] == l && arr[n] == r)
		l--, r++;
	
	cout << l << "\n";
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