#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	if (m == 1)
		cout << n - 1 << "\n";
	else
		cout << 1LL * n * (m - 1);	
	return 0;
}