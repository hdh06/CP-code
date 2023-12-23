#include <bits/stdc++.h>

using namespace std;

string const slp = "GSPVHCUTE";

vector<int> g[31];

int cnt[10];

int tong = 0;

vector<int> state(10), kq(10);

int st = 0;

void emrua(int k, int n){
	if (n == tong + 1){
		st++;
		if (st == k) kq = state;
		return;
	}

	for (int i = 0; i <= 9; i++){
		if (i == 0) {
			st++;
			if (st == k) kq = state;
		}
		else{ 
			if (cnt[i] == 0) continue;
			bool flag = 0;
			for (auto x: g[n]) if (state[x] == i) flag = 1;
			if (flag) continue;
			emrua(k, n + 1);
		}
	}
}

int main(){
	map<char, int> m;
	for (int i = 0; i < 9; i++)
		cin >> m[slp[i]];

	int dem = 0;
	for (auto x: m) cnt[++dem] = x.second;

	for (int i = 1; i <= 9; i++) tong += cnt[i];
	cnt[0] = 1000;
	int q; cin >> q;
	for (q--){
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		g[b].push_back(a);
	}
	int k; cin >> k;
	return 0;
}