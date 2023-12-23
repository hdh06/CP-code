#include <bits/stdc++.h>

using namespace std;

struct sgt{
	int lt, rt;
	vector<int> tree;
	sgt(){}
	sgt(int lt, int rt): lt(lt), rt(rt){
		tree.assign(4 * (rt - lt + 1) + 1, 0);
	}
	
	void upd(int p, int val, int x, int l, int r){
		if (p < l || r < p) return;
		if (l == r){
			tree[x] = val;
			return;
		}
		int mid = (l + r) >> 1;
		upd(p, val, 2 * x, l, mid);
		upd(p, val, 2 * x + 1, mid + 1, r);
		tree[x] = max(tree[2 * x], tree[2 * x + 1]);
	}
	void upd(int p, int val){
		// assert(lt <= p && p <= rt);
		upd(p - lt + 1, val, 1, 1, rt - lt + 1);
	}
	
	int get(int L, int R, int x, int l, int r){
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) return tree[x];
		int mid = (l + r) >> 1;
		return max(get(L, R, 2 * x, l, mid), get(L, R, 2 * x + 1, mid + 1, r));
	}
	int get(int L, int R){
		// assert(lt <= L && R <= rt);
		return get(L - lt + 1, R - lt + 1, 1, 1, rt - lt + 1);
	}
};

int const N = 2e5 + 1;

int n, q;
int v[N];

vector<int> g[N];

int sz[N], trv[N], trv_id = 0, p[N], h[N];

void DFS(int v){
	sz[v] = 1;
	for (auto u: g[v]) if (u != p[v]){
		p[u] = v;
		h[u] = h[v] + 1;
		DFS(u);
		sz[v] += sz[u];
	}
}

int hhd[N], hid[N], hvl_id = 1, hsz[N]; 

sgt tree[N];

void HVL(int v){
	if (!hhd[hvl_id]) hhd[hvl_id] = v;
	hid[v] = hvl_id;
	hsz[hvl_id]++;
	
	trv[v] = ++trv_id;	
	
	int maxV = 0;
	for (auto u: g[v]) if (u != p[v]){
		if (maxV == -1 || sz[u] > sz[maxV])
			maxV = u;
	}
	
	if (maxV)
		HVL(maxV);
		
	for (auto u: g[v]) if (u != p[v] && u != maxV){
		hvl_id++;
		HVL(u);
	}
}

int getMax(int l, int r){
	int ans = 0;
	while (hid[l] != hid[r]){
		if (h[hhd[hid[l]]] > h[hhd[hid[r]]]){
			ans = max(ans, tree[hid[l]].get(trv[hhd[hid[l]]], trv[l]));
			l = p[hhd[hid[l]]];
		}else{
			ans = max(ans, tree[hid[r]].get(trv[hhd[hid[r]]], trv[r]));
			r = p[hhd[hid[r]]];
		}
	}
	if (trv[l] > trv[r]) swap(l, r);
	
	return max(ans, tree[hid[l]].get(trv[l], trv[r]));
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> q;	
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	DFS(1);
	HVL(1);
	
	for (int i = 1; i <= hvl_id; i++)
		tree[i] = sgt(trv[hhd[i]], trv[hhd[i]] + hsz[i] - 1);
	
	for (int i = 1; i <= n; i++)
		tree[hid[i]].upd(trv[i], v[i]);
	
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int p, val; cin >> p >> val;
			tree[hid[p]].upd(trv[p], val);
		}
		if (t == 2){
			int l, r; cin >> l >> r;
			cout << getMax(l, r) << " ";
		}
	}
	
	return 0;
}