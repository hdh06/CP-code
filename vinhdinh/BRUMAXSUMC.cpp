#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, q; cin >> n >> q;
	priority_queue<int> myque;

	for (int i = 0; i < n; i++){
		int t; cin >> t;
		myque.push(t);
	}

	vector<int> diff(n + 2, 0);

	while (q--){
		int l, r; cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}	

	int d = 0;

	vector<int> p(n);

	for (int i = 1; i <= n; i++){
		d += diff[i];
		p.push_back(d);
	}

	sort(p.begin(), p.end(), greater<int>());

	long long tong = 0;

	for (auto x: p){
		tong += x*1LL*myque.top();
		myque.pop();	
	}

	cout << tong;
	return 0;
}