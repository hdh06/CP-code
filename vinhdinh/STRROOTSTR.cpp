#include <bits/stdc++.h>

using namespace std;

int const N = 7e7;

bool is[N] = {};

int main(){
	int n; cin >> n;

	int dem = 0;

	for (int i = 1; i <= n; i++){
		int h = 0;
		string s; cin >> s;
		for (auto x: s){
			h |= (1 << (x - 'a'));
		}
		if (!is[h]){
			dem++;
			is[h] = true;
		}
	}

	cout << dem;
	return 0;
}