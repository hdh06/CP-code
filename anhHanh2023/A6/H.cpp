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
#define file "shipping"

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

int const N = 50 * 50 * 50 + 1;
int const Q = 500 * 500 + 1; 

int n, m, k, q;

vi g[N];

struct Store{
	int place, cap, price;
	Store(){place = cap = price = 0;}
	Store(int place, int cap, int price): place(place), cap(cap), price(price){}
	
	void read(){cin >> place >> cap >> price;}
};

struct Query{
	int need, low, high;
	ll budget;
	
	Query(){}
	
	Query(int need, ll budget) : need(need), budget(budget) {}
};

int const MAX_NEED = 1e9 + 1;
ll const MAX_BUDGET = 1e18 + 1;

struct Sgt{
	int n;
	int cnt[1 << 18];
	ll sum[1 << 18];
	
	Sgt(){}
	
	Sgt(int n) :n(n){
		
		memset(cnt, 0, sizeof cnt);
		memset(sum, 0, sizeof sum);
	}
	
	void reset(){
		memset(cnt, 0, sizeof cnt);
		memset(sum, 0, sizeof sum);
	}
	
	void upd(int pos, int cap, int cost){
		// debug(pos, cap, cost);
		int x = 1, l = 1, r = n;
		while (true){
			cnt[x] += cap;
			sum[x] += 1LL * cap * cost;
			cnt[x] = min(cnt[x], MAX_NEED);
			sum[x] = min(sum[x], MAX_BUDGET);
			
			if (l == r) return;
			
			int mid = (l + r) >> 1;
			if (pos > mid) x = 2 * x + 1, l = mid + 1;
			else x = 2 * x, r = mid;
		}
	}
	
	bool isEnough(int need, ll budget){
		if (cnt[1] < need) return false;
		int x = 1, l = 1, r = n;
		
		while (true){
			if (l == r)
				return sum[x] / cnt[x] * need <= budget;
			
			int mid = (l + r) >> 1;
			if (cnt[2 * x] >= need)
				x = 2 * x, r = mid;
			else{
				budget -= sum[2 * x];
				need -= cnt[2 * x];
				x = 2 * x + 1, l = mid + 1;
			}
		}
	}
};

Store stores[N];
Query queries[Q];
vi gQuery[N];
Sgt Stree;

int const QNODE = 11;
int dis[QNODE][N];

void bfs(int v, int dis[]){
	fill(dis + 1, dis + n + 1, n);
	queue<int> que;
	dis[v] = 0;
	que.push(v);
	while (!que.empty()){
		int v = que.front(); que.pop();
		
		for (auto u: g[v]) if (dis[u] == n){ 
			dis[u] = dis[v] + 1;
			que.push(u);	
		}		
	}
}

ii storesByDis[N];
vii asks;

void calcQuery(int place){
	if (gQuery[place].empty()) return;
	
	for (int i = 1; i <= k; i++) storesByDis[i] = mp(dis[place][stores[i].place], i);
	sort(storesByDis + 1, storesByDis + k + 1);
	
	for (int x: gQuery[place]){
		queries[x].low = 0;
		queries[x].high = n;
	}
	
	while (true){
		asks.clear();
		for (int x: gQuery[place]){
			int &l = queries[x].low, &h = queries[x].high;
			if (l == h) continue;
			asks.pb(mp((l + h) >> 1, x));
		}
		if (asks.empty()) break;
		Stree.reset();
		sort(all(asks));
		
		// if (place == 1) debug(vii(storesByDis + 1, storesByDis + k + 1));
		
		int j = 1;
		for (ii x: asks){
			while (j <= k){
				int z = storesByDis[j].nd;
				if (storesByDis[j].st > x.st) break;
				Stree.upd(z, stores[z].cap, stores[z].price);
				j++;
			}
			// if (place == 1) debug(x, j);
			if (Stree.isEnough(queries[x.nd].need, queries[x.nd].budget)) queries[x.nd].high = x.st;
			else queries[x.nd].low = x.st + 1;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	cin >> k;
	for (int i = 1; i <= k; i++)
		stores[i].read();
		
	sort(stores + 1, stores + k + 1, [](Store A, Store B){
		return A.price < B.price;
	});
		
	cin >> q;
	for (int i = 1; i <= q; i++){
		int place, need; ll budget;
		cin >> place >> need >> budget;
		gQuery[place].pb(i);
		queries[i] = Query(need, budget);
	}	
	
	for (int i = 1; i <= QNODE; i++) bfs(i, dis[i]);
	Stree = Sgt(k);

	for (int i = 1; i <= QNODE; i++) calcQuery(i);
	for (int i = 1; i <= q; i++) cout << (queries[i].low < n? queries[i].low: -1) << " ";
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!