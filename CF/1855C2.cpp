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
#define file "fiel"

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

bool const SINGLE_TEST = 0;

int cnt(int x, int y){
	int ans = 0;
	while (abs(x) < y){
		x += x;
		ans++;
	}
	return ans;
}

void solve(){	
	int n; cin >> n;
	vi arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	int pmax = 0, nmax = 0, pc = 0, nc = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] > 0){
			pc++;	
			if (arr[i] > arr[pmax]) pmax = i;
		}
		if (arr[i] < 0){
			nc++;
			if (-arr[i] > -arr[nmax]) nmax = i;
		}
 	} 	
 	
 	if (pc == 0 && nc == 0){cout << "0\n"; return;}
 	
 	vii ans;
 	if (pc == 0)
 		for (int i = n - 1; i >= 1; i--) arr[i] += arr[i + 1], ans.pb({i, i + 1});
	else
	if (nc == 0)
		for (int i = 2; i <= n; i++) arr[i] += arr[i - 1], ans.pb({i, i - 1});

	else 
	if (cnt(arr[nmax], arr[pmax]) + pc > cnt(arr[pmax], -arr[nmax]) + nc){
		// assert(cnt(arr[pmax]) + nc + 19 <= 31);
		while (abs(arr[pmax]) < -arr[nmax])
			arr[pmax] += arr[pmax], ans.pb({pmax, pmax});
		
		for (int i = 1; i <= n; i++){
			if (arr[i] < 0) arr[i] += arr[pmax], ans.pb({i, pmax});
			if (i > 1) arr[i] += arr[i - 1], ans.pb({i, i - 1});
		}
 	}else{
 		// assert(cnt(arr[nmax]) + pc + 19 <= 31);
 		while (abs(arr[nmax]) < arr[pmax])
 			arr[nmax] += arr[nmax], ans.pb({nmax, nmax});
 		
 		for (int i = n; i >= 1; i--){
 			if (arr[i] > 0) arr[i] += arr[nmax], ans.pb({i, nmax});
 			if (i < n) arr[i] += arr[i + 1], ans.pb({i, i + 1});
 		}
 	}
	
	
	debug(arr);
	
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
}//khong phai _HDH, _HDH ko xai template!!!