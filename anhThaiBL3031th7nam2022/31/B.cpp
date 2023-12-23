#include <bits/stdc++.h>

using namespace std;

int f(int n){return n & -n;}

int main(){
	int n; cin >> n;
	if (f(n) == n)
		cout << 0 << endl;
	else{
		cout << f(n) << endl;
		n -= f(n);
	}
	while (n > 0){
		int x;
		cin >> x; n -= x;
		cout << f(n) << endl;
		n -= f(n);
	}
	return 0;
}