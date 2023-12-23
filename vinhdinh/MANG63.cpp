#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	for (int t = n; t--;){
		int tong = 0;
		for (int i = 0; i < n; i++){
			int temp;
			cin >> temp;

			if (temp % 2 == 0) tong += temp;
		}
		cout << tong << endl;
	}
	return 0;
}