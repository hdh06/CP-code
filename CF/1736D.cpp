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

int const N = 2e5 + 1;

int arr[N];

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = ' ' + s;
	int cnt = 0;
	vi z;
	for (int i = 1; i <= n; i++){
		if (s[2 * i] != s[2 * i - 1]){
			cnt++;
			if (s[2 * i] == (cnt & 1? '0' : '1'))
				z.pb(2 * i);
			else z.pb(2 * i - 1);
		}
	}	
	if (cnt & 1){
		cout << "-1\n";
		return;
	}
	cout << z.size() << " ";
	for (auto x: z) cout << x << " "; cout << "\n";
	
	for (int i = 1; i <= n; i++)
		cout << 2 * i - 1 << " \n"[i == n];
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