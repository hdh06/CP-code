#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
	if (x < 2) return 0;
	for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}

int main(){
	long long n; cin >> n;	
	
	int ans = 0;
	for (int i = 2; 1LL * i * i <= n; i++)
		ans += isPrime(i);
	
	cout << ans;
	return 0;
}