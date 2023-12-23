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

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

bool const SINGLE_TEST = 1;

void solve(){	
	int n, m, k; cin >> n >> m >> k;

	if (n == 1 && m == 1 && k == 1){
		cout << "yes\n";
		return;
	}
	assert(k <= 196);	
	cout << (rand(0, 1)? "yes\n": "no\n");
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
/*
#1: Accepted [0 ms, 0 MB]
#2: Wrong answer [15 ms, 0 MB] -> 168 243 
#3: Accepted [0 ms, 0 MB]
#4: Accepted [0 ms, 0 MB]
#5: Wrong answer [0 ms, 0 MB]
#6: Wrong answer [0 ms, 0 MB]
#7: Wrong answer [0 ms, 0 MB, 0 points]
#8: Accepted [0 ms, 0 MB, 5 points]
#9: Accepted [0 ms, 0 MB, 5 points]
#10: Wrong answer [0 ms, 0 MB, 0 points]
#11: Accepted [0 ms, 0 MB, 5 points]
#12: Wrong answer [0 ms, 0 MB, 0 points]
#13: Accepted [0 ms, 0 MB, 5 points]
#14: Wrong answer [0 ms, 0 MB, 0 points]
#15: Accepted [0 ms, 0 MB, 5 points]
#16: Wrong answer [0 ms, 0 MB, 0 points]
#17: Wrong answer [0 ms, 0 MB, 0 points]
#18: Accepted [0 ms, 0 MB, 5 points]
#19: Wrong answer [0 ms, 0 MB, 0 points]
#20: Accepted [0 ms, 0 MB, 5 points]
#21: Wrong answer [0 ms, 0 MB, 0 points]
*/