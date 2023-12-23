#include <bits/stdc++.h>

using namespace std;

int const INF = 1e6 + 1;

int main(){
	int n; cin >> n;
	int a = -INF, b = -INF, c = INF, d = INF;
	while (n--){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		a = max(a, x1);
		b = max(b, y1);
		c = min(c, x2);
		d = min(d, y2);
	}	

	cout << a << " " << b << " " << c << " " << d << " ";

	cout << (c - a)*(d - b);
	return 0;
}