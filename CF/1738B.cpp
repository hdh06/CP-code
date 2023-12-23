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
int const INF = 1e9;

void solve(){
	int n, k; cin >> n >> k;
	vi s(k + 1);
	for (int i = 1; i <= k; i++)
		cin >> s[i]; 
	
	if (abs(s[1]) % (n - k + 1) == 0){
		s[0] = s[1] - s[1] / (n - k + 1);
	}else s[0] = s[1] - s[1] / (n - k + 1) - 1 * (s[1] > 0);
	

	debug(s[0]);
	
	for (int i = 2; i <= k; i++){
		if (s[i] - s[i - 1] < s[i - 1] - s[i - 2]){
			cout << "No\n";
			return;
		}
	}
	
	cout << "Yes\n";
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