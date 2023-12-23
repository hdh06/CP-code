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

int const N = 1e4 + 1;

int n, m;
ii a[N], b[N];

int p[N], rmd[N];

ll dis(ii a, ii b){
	return 1LL * (a.st - b.st) * (a.st - b.st) + 1LL * (a.nd - b.nd) * (a.nd - b.nd);
}

bool f(ll mid){
	iota(rmd + 1, rmd + n + 1, 1);
	int s = n;
	queue<int> que;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= s;){
			if (dis(a[i], b[rmd[j]]) <= mid){
				p[rmd[j]] = i + n;
				que.push(rmd[j]);
				swap(rmd[j], rmd[s]); s--;
			}else j++;
		}
	}
	
	while (!que.empty()){
		int v = que.front(); que.pop();
		for (int j = 1; j <= s;){
			if (dis(b[v], b[rmd[j]]) <= mid){
				p[rmd[j]] = v;
				que.push(rmd[j]);
				swap(rmd[j], rmd[s]); s--;
			}else j++;
		}
	}
	
	return s == 0;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i].st >> a[i].nd;
	for (int i = 1; i <= n; i++) cin >> b[i].st >> b[i].nd;
	
	ll ans = -1;
	for (ll l = 0, r = 1e15; l <= r;){
		ll mid = (l + r) >> 1;
		if (f(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	f(ans);
	
	// debug(vi(p + 1, p + n + 1));
	
	ll sum = 0;
	vector<pair<char, pair<int, int> > > trace;
	bool vis[N] = {};
	for (int i = 1; i <= n; i++){
		if (p[i] > n){
			sum += dis(a[p[i] - n], b[i]);
			trace.pb(mp('s', mp(p[i] - n, i)));
			vis[p[i] - n] = 1;
 		}
		else{
			sum += dis(b[p[i]], b[i]);
			trace.pb(mp('u', mp(p[i], i)));
		// debug(p[i], i);
		}
	}
	for (int i = 1; i <= m; i++) if (!vis[i]){
		int minn = -1;
		for (int j = 1; j <= n; j++)
			if (minn == -1 || dis(a[i], b[j]) < dis(a[i], b[minn]))
				minn = j;
		if (minn != -1){
			sum += dis(a[i], b[minn]);
			trace.pb(mp('s', mp(i, minn)));
		}
	}
		
			
	cout << sum << "\n";
	cout << trace.size() << "\n";
	for (auto x: trace) cout << x.st << " " << x.nd.st << " " << x.nd.nd << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!