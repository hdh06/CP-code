#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int calc(int n){
	int ans = 0;
	while (n > 0){
		ans ++;
		n -= (int)sqrt(n)*(int)sqrt(n);
	}
	return ans;
}

int main(){
	int n; cin >> n;
	int maxn = 0;
	int fre[100] = {};
	for (int i = 1; i <= n; i++){
		maxn = max(maxn, calc(i));
		fre[min(maxn, 99)]++;
		// cout << i << ": " << calc(i) << " .max " << maxn << "\n";
	}

	for (int i = 1; i <= 10; i++){
		cout << i << " -> " << fre[i] << " " << (int)sqrt(fre[i])*(int)sqrt(fre[i]) << "\n";
	}
	return 0;
}