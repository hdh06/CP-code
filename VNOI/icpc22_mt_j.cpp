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
typedef array<int, 4> iiii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int n, m, a, b;

vector<iiii> out;

void ans(int l, int r){
	if (r < l) return;
	out.pb({l % m, l / m, r % m + 1, r / m + 1});
}
void print(){
	cout << out.size() << "\n";
	for (auto x: out) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
}

void solve(){
	cin >> n >> m >> a >> b;
	
	a--, b--;
	
	int x = a % m;
	int y = b % m;
	
	if (b == n - 1){
		cout << "yet\n";
		return;
	}
	
	ans(a, (a / m + 1) * m - 1);
	ans((a / m + 1) * m, (b / m) * m - 1);
	ans((b / m) * m, b);
	
	print();
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