#include <bits/stdc++.h>

using namespace std;

int main(){
	int const N = 10;
	int hash[N] = {};
	int n;
	cin >> n;
	for (int x = 1; x <= n; x++){
		while(x != 0){
			hash[x % 10]++;
			x /= 10;
		}
	}
	for (int i = 0; i < N; i++){
		if (hash[i] != 0){
			cout << i << " " << hash[i] << endl;
		}
	}
	return 0;
}
