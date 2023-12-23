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
#define file "luxtable"

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

int const N = 2e5 + 1;
int n;
int arr[N];

namespace sub1{
	void solve(){
		vi z;
		for (int i = 1; i <= n; i++) z.pb(arr[i]);
		// z.pb(1000000000);
		// z.pb(1000000001);
		sort(all(z));
		z.erase(unique(all(z)), z.end());
		int ans = INT_MAX;
		for (int i = 0; i < z.size(); i++)
			for (int j = 0; j < z.size(); j++) if (i != j){
				int cnt = 0;
				int curr = 0;
				for (int k = 1; k <= n; k++){
					if ((k % 2 == 0 && arr[k] == z[i]) || (k % 2 != 0 && arr[k] == z[j])){
						curr++;
					}else{
						if (curr > 1) cnt++;
						curr = 0;
					}
					if ((k % 2 == 0 && arr[k] != z[j]) || (k % 2 != 0 && arr[k] != z[i]))
						cnt++;
					// debug(z[i], z[j], cnt, curr);
				}
				if (curr > 1) cnt++;
					debug(z[i], z[j], cnt, curr);
				ans = min(ans, cnt);
			}
		cout << ans << "\n";	
	}
}

namespace subwa{
	void solve(){
		cin >> n;
		map<int, int> cnt1, cnt2;
		
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			if (i & 1) cnt1[arr[i]]++;
			else cnt2[arr[i]]++;
		}
	
		vii v1(all(cnt1)), v2(all(cnt2));
		
		reverse(all(v1));
		reverse(all(v2));	
		
		int a = -1, b = -1;
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++) if (v1[i].st != v2[j].st){
				if (a == -1 || v1[i].nd + v2[j].nd > v1[a].nd + v2[b].nd)
				a = i, b = j;
			}
		
		cout << n - v1[a].nd - v2[b].nd << "\n";
	}
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	subwa::solve();
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	int t; cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!

