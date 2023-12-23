#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int arr[N];

int calc(int i, int n){
	if (n == 0) return arr[i];
	int k = n & (-n);
	return calc(i, n - k) ^ calc(i + k, n - k);
}

int main(){
	int n; cin >> n;	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << calc(0, n - 1);
	return 0;
}