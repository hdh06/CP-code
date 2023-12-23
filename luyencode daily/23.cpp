#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n; cin >> n;
	cout << ((n - 1)*(n - 2)/2 - 3 * (n / 2 - (1 - n % 2)) + 2 * (n / 3 - (n - 1)/3))/6;
	return 0;
}