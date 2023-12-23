#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int tong = 0;
	while (n--){
		tong += pow(n + 1, 4);
	}
	cout << tong;
	return 0;
}