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
#define file "flie"

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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int const N = 1e4 + 1;

bool sang[N] = {1, 1};
void init(){
	for (int i = 2; i * i < N; i++) if (!sang[i])
		for (int j = i * i; j < N; j += i) sang[j] = 1;
}

ll ask(ll x){
	cout << "? " << x << endl;
	int ans; cin >> ans;
	return ans;
}

int main(){
// 	ios_base::sync_with_stdio(0);//      the
// 	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	init();

	int n; cin >> n;
	cout << (int)log2(n) << endl;

	ll ans = 1;
	for (int i = 2; i <= n; i++) if (!sang[i]){
		while (ans * i <= n){
			int z = ask(ans * i);
			ans *= z / ans;
			if (z != ans * i) break;
		}
	}
	
	cout << "! " << ans << endl;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!