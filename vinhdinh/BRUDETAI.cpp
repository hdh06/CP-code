#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int fre[N] = {};

int main(){
	int n;
	cin >> n;

	while(n--){
		int temp;
		cin >> temp;
		fre[temp]++;
	}

	int dem = 0;
	for (int i = 1; i < N; i++){
		dem += fre[i]/i;
	}
	cout << dem;
	return 0;
}