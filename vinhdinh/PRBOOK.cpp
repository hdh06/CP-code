#include <bits/stdc++.h>

using namespace std;

int num[10] = {};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	char c; long long tong = 0;
	// c = getchar();
	while (cin >> c){
		num[c - '0'] ++;
		tong += c - '0';
		// c = getchar();
	}

	if (num[0] == 0 || tong % 3 != 0){
		cout << -1; 
		return 0;
	}

	for (int i = 9; i >= 0; i--){
		for (int j = 0; j < num[i]; j++) cout << i;
	}
	return 0;
}