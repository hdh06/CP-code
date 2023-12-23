#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c; cin >> a >> b >> c;
	if (a == b && b == c) cout << 0;
	else if (a != b && b != c && c != a) cout << 0;
	else cout << 1;
	return 0;
}