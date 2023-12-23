#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;
int const MOD = 1e9 + 7;

int n;
ll tree[N];
void upd(int x, int v){
	for (; x < N; x += x & - x)
		(tree[x] += v + MOD) %= MOD;
}
ll get(int x){
	ll ans = 0;
	for (;x > 0; x -= x & -x)
		(ans += tree[x]) %= MOD;
	return ans;
}
void rupd(int l, int r, int v){
	upd(l, v);
	upd(r + 1, -v);
}

int main(){
	cin >> n; 
	rupd(1, 1, 1);
	for (int i = 1; i <= n - 1; i++){
		int l, r; cin >> l >> r;
		rupd(l, r, get(i));		
	}
	
	for (int i = 1; i <= n; i++)
		cout << get(i) << " ";
	return 0;
}