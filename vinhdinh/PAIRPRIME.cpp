#include <bits/stdc++.h>

using namespace std;

bool pc(int n){
	if (n <= 1) return false;
	
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; 1LL * i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, t, a = 0, b; cin >> n; 
	for (int i = 1; i <= n; ++i){
		cin >> t;
		if (pc(t)) ++a;
	}
	b = n - a;

	cout << 1LL * a * b + 1LL * a * (a - 1) / 2;
	// cout << a;
	return 0;
}