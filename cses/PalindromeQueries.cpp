#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;

int const N = 2e5 + 1, A = 1e9 + 7, B = 1e9 + 9;

int mpow(int x, int n){
	if (n == 0) return 1;
	int ans = mpow(x, n / 2);
	if (n & 1) return 1LL * ans * ans % B * x % B;
	return 1LL * ans * ans % B;
}

int p[N], inv[N];
void init(){
	p[0] = inv[0] = 1;
	for (int i = 1; i < N; i++){
		p[i] = (1LL * p[i - 1] * A) % B;
		inv[i] = mpow(p[i], B - 2);
	}
}

struct Fenw{
	int n;
	vector<int> tree;
	Fenw(){}
	
	void init(int _n){
		n = _n;
		tree.resize(n + 1);
	}
	void upd(int pos, int k){
		pos++;
		for (int i = pos; i <= n; i += i & -i)
			tree[i] = (1LL * tree[i] + k + B) % B;
	}
	int get(int pos){
		pos++;
		int ans = 0;
		for (int i = pos; i > 0; i -= i & -i)
			ans = (1LL * ans + tree[i]) % B;
		return ans;
	}
};

struct _hash{
	string s;
	int n;
	Fenw h;
	_hash(string _s){
		s = _s;
		n = s.size();
		h.init(n);
		h.upd(0, s[0]);
		for (int i = 1; i < n; i++)
			h.upd(i, (1LL * s[i] * p[i]) % B);
	}
	_hash(){}
	
	void upd(int pos, char c){
		h.upd(pos, - 1LL * s[pos] * p[pos] % B);
		s[pos] = c;
		h.upd(pos, + 1LL * s[pos] * p[pos] % B);
	}
	
	int get(int l, int r){
		return 1LL * (1LL * h.get(r) - h.get(l - 1) + B) % B * inv[l] % B;
	}
};

signed main(){
	init();
 	cin >> n >> m;
	cin >> s;
		
	_hash h1(s), h2(string(s.rbegin(), s.rend()));
	
	while (m--){
		int type; cin >> type;
		if (type == 1){
			int pos; char c; cin >> pos >> c; pos--;
			h1.upd(pos, c);
			h2.upd(n - pos - 1, c);
		}else{
			int l, r; cin >> l >> r; l--, r--;
			if (h1.get(l, r) == h2.get(n - r - 1, n - l - 1))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}