#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const MOD = 1e9 + 7;

int n, m;
int tree[N << 2] = {};
int lzA[N << 2] = {};
int lzB[N << 2] = {};

int td(int n){
	return n * (n + 1) / 2;
}

int rt(int L, int l, int r){
	return rd(r - L) - td(l - 1 - L);
}

void down(int x){
	int &a = lzA[x];
	int &b = lzB[x];

	lzA[2 * x] += a;
	lzA[2 * x + 1] += 

	lzB[2 * x] += b;
	lzB[2 * x + 1] += b;
	b = 0;
}

void upd(int L, int R, int A, int B, int x = 1, int l = 1, int r = n){
	if (r < L || R < l) return;
	if (L <= l && r <= R){
		tree[x] += rt(L, l, r) * A + (l - r + 1) * B;
		lzA[x] += A;
		lzB[x] += B + rt(L, L, l - 1) * A;
		return;
	}


}

int main(){	
	cin >> n >> m;
	return 0;
}