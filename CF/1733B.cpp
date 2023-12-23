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
	int n, x, y; cin >> n >> x >> y;
	if (x != 0 && y != 0){
		cout << "-1\n";
		return;
	}
	if (x == 0 && y == 0){
		cout << "-1\n";
		return;
	}
	if (x < y) swap(x, y);
	
	n--;
	
	if (n % x == 0){
		int id = 2;
		while (n){
			for (int i = 1; i <= x; i++)
				cout << id << " ";
			id += x;
			n -= x;
		}	
	}
	else cout << -1;
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