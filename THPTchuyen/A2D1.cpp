#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	for (int i = 1; i <= n * n; i++){
		int c;
		cin >> c;
		cout << c << " ";
		if (i % n == 0) cout << "\n";
	}	
	return 0;
}