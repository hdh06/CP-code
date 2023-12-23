#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m = INT_MAX;
	int tong = 0;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		m = min(m, b);
		tong += m*a;
	}
	cout << tong;
	return 0;
}