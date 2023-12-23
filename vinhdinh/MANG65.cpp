#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, dem = 0, tong = 0; 
	cin >> n;

	for (int t = n; t--;){
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;

			if (i == dem) tong += temp;
		}
		dem++;
	}

	cout << tong;
	return 0;
}