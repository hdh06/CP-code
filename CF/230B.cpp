#include <bits/stdc++.h>

using namespace std;

bool pc(int x){
	if (x <= 1) return false;
	for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
	return true;
}

int main(){
	int n; cin >> n;
	while (n--){
		long long x; cin >> x;
		long long z = sqrt(x);
		if (!pc(z)) cout << "NO\n";
		else if (x == z * z) cout << "YES\n";
		else cout << "NO\n";
	}	
	return 0;
}