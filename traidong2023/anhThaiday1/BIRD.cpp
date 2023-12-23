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

int const N = 1e6 + 5;

int n;
int arr[N];

int link[N];

int l[N];

int find(int v){
	return link[v] = link[v] == v? v : find(link[v]);
}

bool unite(int a, int b){
	// debug(a, b);
	a = find(a), b = find(b);
	if (a == b) return false;
	if (a < b) swap(a, b); 
	link[b] = a;
	l[a] = min(l[a], l[b]);
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	int n; cin >> n;
	priority_queue<ii> que;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		que.push(mp(arr[i], - i));
	}

	
	iota(link + 1, link + n + 2, 1);
	iota(l + 1, l + n + 2, 1);
	
	ll ans = 0;
	while (!que.empty()){
		int x =  - que.top().nd;
		ans += 1LL * arr[x] + arr[l[x] - 1] + arr[find(x + 1)];
		// debug(x);
		// debug(l[x]);
		// debug(find(x + 1));
		// debug(arr[x] + arr[l[x] - 1] + arr[find(x + 1)]);
		
		// if (l[x] > 1) unite(l[x] - 1, x);
		unite(x, x + 1);
		que.pop();
	}

	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!