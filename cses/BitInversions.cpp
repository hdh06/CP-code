#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1100
#endif

using namespace std;

#define st first
#define nd second

int const N = 2e5 + 1;

string s;
int n, m;

struct node{
	int pre = 0, suf = 0, tpre = 0, tsuf = 0;
	int ans = 0;
	int sz = 1;
	node(){}
	node(int pre, int suf, int tpre, int tsuf, int ans, int sz): pre(pre), suf(suf), tpre(tpre), tsuf(tsuf), ans(ans), sz(sz){}
};

node merge(node a, node b){
	node c;
	c.ans = max(a.ans, b.ans);
	if (a.tsuf == b.tpre) c.ans = max(c.ans, a.suf + b.pre);
	c.pre = (a.pre == a.sz? a.pre + (a.tpre == b.tpre? b.pre: 0): a.pre);
	c.suf = (b.suf == b.sz? b.suf + (b.tsuf == a.tsuf? a.suf: 0): b.suf);
	c.tpre = a.tpre;
	c.tsuf = b.tsuf;
	c.sz = a.sz + b.sz;
	return c;
}

node tree[N << 2];

void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		if (l <= n) tree[x] = node(1, 1, s[l] - '0', s[l] - '0', 1, 1);
		return;
	}
	
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

void upd(int pos, int x = 1, int l = 1, int r = n){
	if (pos < l || r < pos) return;
	if (l == r){
		tree[x].tpre ^= 1;
		tree[x].tsuf ^= 1;
		s[l] = (s[l] == '0'? '1': '0');
		return;
	}
	
	int mid = (l + r) >> 1;
	upd(pos, 2 * x, l, mid);
	upd(pos, 2 * x + 1, mid + 1, r);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

int main(){
	cin >> s;
	n = s.size();
	s = ' ' + s;	
	cin >> m;
	
	build();
	
	while (m--){
		int x; cin >> x;
		upd(x);
		cout << tree[1].ans << " ";
	}
	return 0;
}