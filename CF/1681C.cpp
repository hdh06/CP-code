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
	vector<ii> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i].st;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].nd;
		
	vector<ii> ans;
	for (int i = 1; i <= n; i++){
		int pos = i;
		for (int j = i + 1; j <= n; j++)
			if (arr[j].st < arr[pos].st) pos = j;
		if (pos != i) ans.pb({i, pos});
		swap(arr[i], arr[pos]);
	}
	
	for (int l = 1; l <= n;){
		int r = l;
		while (r < n && arr[r + 1].st == arr[l].st) r++;
		for (int i = l; i <= r; i++){
			int pos = i;
			for (int j = i + 1; j <= r; j++)
				if (arr[pos].nd > arr[j].nd) pos = j;
			if (pos != i) ans.pb({i, pos});
			swap(arr[i], arr[pos]);
		}
		if (arr[l - 1].nd > arr[l].nd){
			cout << "-1\n";
			return;
		}
		l = r + 1;
	}
	
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x.st << " " << x.nd << "\n";
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