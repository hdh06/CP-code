#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int tong = 0;
	for (int t = n; t > 0; tong += t % 10, t /= 10);

	cout << (tong % 10 == 9? "YES" : "NO");
	return 0;
}