#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n; 
	n--;
	long long x1, y1, x2, y2, x, y;
	cin >> x1 >> y1;
	x = x1, y = y1;

	long long tong = 0;
	while(n --){
		cin >> x2 >> y2;
		tong += x1*y2 - x2*y1;
		x1 = x2, y1 = y2;
	}
	tong += x1*y - y1*x; 
	cout << abs(tong);
	return 0;
}