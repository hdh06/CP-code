#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2*1e5 + 1;

int n; ll arr[N];

int main(){
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	int pos = n/2 + (n % 2 != 0);
	ll tong = 0;

	for (int i = 1; i <= n; i++){
		tong += abs(arr[i] - arr[pos]);
	}

	cout << tong;
	
	return 0;
}