#include <bits/stdc++.h>

using namespace std;

string cases[] = {"<", ">", "<=", ">=", ">=", "<=",">","<"};

/*
0: <, 1: >
2: <=, 3: >= 
= -> +1
REVERSE ((k + 4) % 8):
4: >=, 5: <=
6: >, 7: <
*/

int main(){
	int t; cin >> t;
	int l = INT_MIN, r = INT_MAX;
	while(t--){
		string dau; cin >> dau;
		int n; cin >> n;
		char c; cin >> c;

		int k;
		if (dau[0] == '<') k = 0;
		if (dau[0] == '>') k = 1;
		if (dau.size() == 2) k += 2;

		if (c == 'N') k = (k + 4) % 8;
		dau = cases[k];

		if (dau[0] == '<'){
			if (dau.size() != 2){
				r = min(r, n - 1);
			}
			r = min(r, n);
		}

		if (dau[0] == '>'){
			if (dau.size() != 2){
				l = max(l, n + 1);
			}
			l = max(l, n);
		}
		// cout << dau << " " << l << " " << r << endl;
	}	
	
	cout << (l <= r? l: -1);
	return 0;
}