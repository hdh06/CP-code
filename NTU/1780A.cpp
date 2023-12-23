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
	vi C, L;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		if (arr[i] & 1) L.pb(i);
		else C.pb(i);
	}
	
	if (L.size() == 0){
		cout << "NO\n";
		return;
	}
	if (L.size() >= 3){
		cout << "YES\n";
		cout << L[0] << " " << L[1] << " " << L[2] << "\n";
		return;
	}
	if (C.size() < 2){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << L[0] << " " << C[0] << " " << C[1] << "\n";
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