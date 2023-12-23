#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back
#define st first
#define nd second

int const N = 1e6 + 5;

int n;

vi g[N];

int in[N], out[N], id = 0, h[N];

int tree[N];
void upd(int x, int val){for (;x < N; x += x & -x) tree[x] += val;}
int get(int x){int ans = 0; for (;x > 0; x -= x & -x) ans += tree[x]; return ans;}

void DFS(int v, int p = -1){
    in[v] = ++id;
    for (auto u: g[v]) if (u != p){
        h[u] = h[v] + 1;
        DFS(u, v);
    }
    out[v] = id;
}

void init(int n, vector<pair<int,int> > e){
    ::n = n;
    
    for (auto x: e) g[x.st].pb(x.nd), g[x.nd].pb(x.st);
    DFS(1);
    upd(in[1], 1);
    upd(n + 1, -1);
    return;
}

void close(int u,int v){
    if (h[u] < h[v]) swap(u, v);
    int val = get(in[u]);
    upd(in[u], -val + u);
    upd(out[u] + 1, +val - u);
}

bool question(int u,int v){
    return get(in[u]) == get(in[v]);
}