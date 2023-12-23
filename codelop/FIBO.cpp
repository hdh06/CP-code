#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0) return false;
	}
	return true;
}

int const N = 1e5 + 7 + 1;
int f[N] = {0, 1, 1};

int main(){
	int m;
	cin >> m;
	if (m <= 1){
		cout << -1;
		return 0;
	}
	int i = 2;
	for (; f[i - 1] <= m; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	i--;i--;
	for (; i >= 3; i--){
		if(checkPrime(f[i])){
			cout << f[i];
			return 0;
		}
	}
	return 0;
}