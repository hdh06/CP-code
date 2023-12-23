#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int fre[N] = {};

int main(){
	int n; 
	cin >> n; 

	for (int i = 1; i <= n; i++){
		int temp; cin >> temp;
		fre[temp] ++;
	}

	cout << *max_element(fre, fre + N);
	return 0;
}