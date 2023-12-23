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

int const N = 1e5 + 1;
int const D = 200;

int n, m, q;

vi g[N];

int arr[N];

struct query{
	int l, r;
	query(){}
	query(int l, int r) :l(l), r(r) {}
};

vector<query> queries;

int Start[N], End[N];

int tree[N];
void upd(int x, int val){
	for (;x < N; x += x & -x) tree[x] += val;
}
int get(int x){
	int ans = 0;
	for (;x > 0; x -= x & -x) ans += tree[x];
	return ans;
}
int getSt(int v){return get(End[v]) - get(Start[v] - 1);}

int id = 0;

int p[N] = {};
int isOn[N];

void DFS(int v){
	Start[v] = ++id;
	for (auto u: g[v]) if (u != p[v]){
		p[u] = v;
		// debug(v, u);
		DFS(u);
	}
	End[v] = id;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif

	cin >> n >> m >> q;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for (int i = 1; i <= m; i++)
		cin >> arr[i];
		
	for (int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		queries.pb(query(l, r));
	}
	
	DFS(1);
	
	sort(all(queries), [](query a, query b){
		if (a.l / D == b.l / D) return a.r < b.r;
		return a.l / D < b.l / D;
	});
	
	
	int l = 1, r = 0;
	int ans = 1;
	for (query que: queries){
		while (que.l < l){
			l--;
			int v = arr[l];
			isOn[v] = 1;
			upd(Start[v], 1);
			for (auto x: g[v]){
				if (!isOn[x]){
					if (x != p[v] && getSt(x))
						ans++;	
					else if ((r - l + 1) - getSt(v)) ans++;
				}else ans--;
			}
		}
		while (r < que.r){
			r++;
			int v = arr[r];
			isOn[v] = 1;
			upd(Start[v], 1);
			for (auto x: g[v]){
				if (!isOn[x]){
					if (x != p[v] && getSt(x))
						ans++;	
					else if ((r - l + 1) - getSt(v)) ans++;
				}else ans--;
			}
			// debug(r, que.r, ans);	
		}
		
		while (l < que.l){
			int v = arr[l];
			isOn[v] = 0;
			for (auto x: g[v]) {
				if (!isOn[x]){
					if (x != p[v] && getSt(x))
						ans--;	
					else if ((r - l + 1) - getSt(v)) ans--;
				}else ans++;
			}
			upd(Start[v], -1);
			l++;
			
		}
		while (que.r < r){
			int v = arr[r];
			isOn[v] = 0;
			for (auto x: g[v]){
				if (!isOn[x]){
					if (x != p[v] && getSt(x))
						ans--;	
					else if ((r - l + 1) - getSt(v)) ans--;
				}else ans++;
			}
			upd(Start[v], -1);
			r--;
			
		}
		cout << ans << "\n";
	}

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!