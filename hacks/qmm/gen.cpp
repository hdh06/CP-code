#include <bits/stdc++.h>

using namespace std;

int main(){
	int n = 9;
	freopen("test.out", "w", stdout);
	cout << ((1 << n) - 1) << " ";
	int m = 0;
	for (int i = 1; i < n; i++){
		m += 1 << (i + (i - 1));
	}
	cout << m << "\n";
	int st = 1;
	for (int j = 1; j < n; j++){
		for (int v = st; v < st + (1 << (j - 1)); v++){
			for (int k = st + (1 << (j - 1)); k < st + (1 << (j - 1)) + (1 << j); k++){
				cout << v << " " << k << "\n";
			}
		}
		st += (1 << (j - 1));
	}
	return 0;
}