#include <bits/stdc++.h>

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

bool const SINGLE_TEST = 1;

int const N = 3e5 + 5;

map<int, int> a, b;

void solve(){
	int n; cin >> n;
	ii arr[N]; 
	for (int i = 1; i <= n; i++){
		cin >> arr[i].st >> arr[i].nd;
		a[arr[i].st]++;
		b[arr[i].nd]++;
	}
	
	sort(arr + 1, arr + n + 1);
	arr[n + 1] = {-1e9 + 1, -1e9 + 1};
	
	ll ans = 0;
	ii curr = {-1e9 + 1, -1e9 + 1};
	int dem = 0;
	for (int i = 1; i <= n + 1; i++){
		if (arr[i] != curr){
			ans += 1LL * dem * (a[curr.st] - dem) * (b[curr.nd] - dem);
			dem = 1;
			curr = arr[i];
		}else dem++;
	}
	
	cout << ans;
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