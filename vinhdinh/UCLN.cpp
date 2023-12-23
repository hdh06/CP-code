#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b;

	cin >> a >> b;

	if (a > b) swap(a, b);

	while (a != 0){
		long long r = b % a;
		b = a;
		a = r;
	}

	cout << b;
	return 0;
}