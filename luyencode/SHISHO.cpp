#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	if (n <= 1) return false;

	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0) return false;
	}

	return true;
}

int reverse(int n){
	int ans = 0, dem = 0;

	while (n > 0){
		ans = ans*10 + n % 10;
		n /= 10;
		dem++;
	}

	while (dem < 4) ans *= 10, dem++;
	return ans;
}

int main(){
	int n, dem = 0; 
	cin >> n;
	while (n--){
		int b; 
		cin >> b; 

		if (isPrime(reverse(b))) dem++;
	}

	cout << dem;
}