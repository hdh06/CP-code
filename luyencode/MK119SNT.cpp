#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int arr[N];

bool checkPrime(int n){
	if (n < 2) return false;

	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;

	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < N; i++){
		if (checkPrime(i)) arr[i] = arr[i - 1] + 1;
		else arr[i] = arr[i - 1];
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		cout << arr[r] - arr[l - 1] << endl;
	}
	return 0;
}