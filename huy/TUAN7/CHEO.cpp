#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;	
	int tong = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int temp;
			cin >> temp;
			if (i + j == n + 1 && temp % 2 != 0) tong += temp;
		}
	}

	cout << tong;
	return 0;	
}