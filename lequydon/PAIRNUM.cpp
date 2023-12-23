#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long hash[100001] = {};

	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		hash[temp]++;
	}

	long long tong = 0;
	for (int i = 1; i <= 100000; i++){
		tong += hash[i]*(hash[i]-1)/2;
	}
	cout << tong;
	return 0;
}