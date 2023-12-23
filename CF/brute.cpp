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
#define file "itnonlazy1"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

int const N = 250001;
int const K = 35;

int n;
vi tree[N << 2];

void merge(vi &c, vi &a, vi &b){
	c.clear();
	for (int i = 0, j = 0; (i < a.size() || j < b.size()) && c.size() < K;){
		if (i != a.size() && (j == b.size() || a[i] > b[j]))
			c.pb(a[i++]);
		else c.pb(b[j++]);
	}
	// debug(c);
}

void upd(int pos, int val, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		tree[x] = vector<int>(1, val);
		return;
	}
	int mid = (l + r) >> 1;
	upd(pos, val, 2 * x, l, mid);
	upd(pos, val, 2 * x + 1, mid + 1, r);
	merge(tree[x], tree[2 * x], tree[2 * x + 1]);
}
void get(vi &ans, int L, int R, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		ans = tree[x];
		return;
	}
	int mid = (l + r) >> 1;
	if (R < mid + 1){
		get(ans, L, R, 2 * x, l, mid);
	}else if (mid < L){
		get(ans, L, R, 2 * x + 1, mid + 1, r);
	}else{
		vi t1, t2;
		get(t1, L, R, 2 * x, l, mid);
		get(t2, L, R, 2 * x + 1, mid + 1, r);
		merge(ans, t1, t2);
	}
}

namespace sub1{
	void solve(){
		int n, q; cin >> n >> q;
		int arr[N];
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		while (q--){
			string s; cin >> s;
			if (s == "SET"){
				int pos, val; cin >> pos >> val;
				arr[pos] = val;
			}
			if (s == "MAX"){
				int l, r, k; cin >> l >> r >> k;
				vi z;
				for (int i = l; i <= r; i++){
					z.pb(arr[i]);
				}
				sort(all(z), greater<int>());
				cout << z[k - 1] << " ";
			}
			if (s == "POS"){
				int l, r, v, k;
				cin >> l >> r >> v >> k;
				int ans = -1;
				for (int i = l; i <= r; i++){
					if (arr[i] >= v) k--;
					if (k == 0){
						ans = i;
						break;
					}
				}
				cout << ans << " ";
			}
		}
		
	}
}

namespace sub2{
	int n;
	int tree[N << 2];
	void upd(int pos, int val, int x = 1, int l = 1, int r = n){
		if (pos < l || r < pos) return;
		if (l == r){
			tree[x] = val;
			return;
		}
		int mid = (l + r) >> 1;
		upd(pos, val, 2 * x, l, mid);
		upd(pos, val, 2 * x + 1, mid + 1, r);
		tree[x] = max(tree[2 * x], tree[2 * x + 1]);
	}
	int get(int L, int R, int x = 1, int l = 1, int r = n){
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) return tree[x];
		int mid = (l + r) >> 1;
		return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	}
	void solve(){
		int q; cin >> n >> q;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			upd(i, x);
		}
		while (q--){
			string s; cin >> s;
			if (s == "SET"){
				int pos, val; cin >> pos >> val;
				upd(pos, val);
			}
			if (s == "MAX"){
				int l, r, k; cin >> l >> r >> k;
				cout << get(l, r) << " ";
			}
			if (s == "POS"){
				int L, R, v, k;
				cin >> L >> R >> v >> k;
				int ans = -1;
				for (int l = L, r = R; l <= r;){
					int mid = (l + r) >> 1;
					if (get(L, mid) >= v){
						ans = mid;
						r = mid - 1;
					}else l = mid + 1;
				}
				cout << ans << " ";
			}
		}
	}
	
}


namespace sub3{
	vi tmp, c;
	int find(int L, int R, int v, int k, int x = 1, int l = 1, int r = n){
		if (l == r){
		    merge(tmp, c, tree[x]);
			if (l <= R && tmp[k - 1] >= v) return l;
			return -1;
		}	
		int mid = (l + r) >> 1;
		merge(tmp, c, tree[2 * x]);
		if (k - 1 < tmp.size() && tmp[k - 1] >= v)
			return find(L, R, v, k, 2 * x, l, mid);
		else{
			merge(c, c, tree[2 * x]);
			return find(L, R, v, k, 2 * x + 1, mid + 1, r);
		}
				
	}
	void solve(){
		int q; cin >> n >> q;
		int arr[N];
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			arr[i] = x;
			upd(i, x);
		}
		while (q--){
			string s; cin >> s;
			if (s == "SET"){
				int p, val; cin >> p >> val;
				arr[p] = val;
				upd(p, val);
			}
			if (s == "MAX"){
				int l, r, k; cin >> l >> r >> k;
				vi ans;
				get(ans, l, r);
				cout << ans[k - 1] << " ";
			}
			if (s == "POS"){
				int L, R, v, k;
				cin >> L >> R >> v >> k;
				cout << find(L, R, v, k) << " ";
			}
		}
	}
}


namespace sub4{
	void solve(){
		int q; cin >> n >> q;
		int arr[N];
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			arr[i] = x;
			upd(i, x);
		}
		while (q--){
			string s; cin >> s;
			if (s == "SET"){
				int p, val; cin >> p >> val;
				arr[p] = val;
				upd(p, val);
			}
			if (s == "MAX"){
				int l, r, k; cin >> l >> r >> k;
				vi ans;
				get(ans, l, r);
				cout << ans[k - 1] << "\n";
			}
			if (s == "POS"){
				int L, R, v, k;
				cin >> L >> R >> v >> k;
				int ans = -1;
				for (int l = L, r = R; l <= r;){
					int mid = (l + r) >> 1;
					vi tmp;
					get(tmp, L, mid);
					if (tmp[k] >= v){
						ans = mid;
						r = mid - 1;
					}else l = mid + 1;
				}
				cout << ans << " ";
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".ans", "w", stdout);
	// int subtask; cin >> subtask;
		// if (subtask == 4) sub4::solve();
	// else 
		// if (subtask == 1) 
			sub1::solve();
	// else 
		// if (subtask == 2) sub2::solve();
	// else 
		// if (subtask == 3) sub3::solve();
	// else sub4::solve();
	
	return 0;
}//OS