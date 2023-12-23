#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;

	long long tong = -1;

	for (int i = 2; i <= sqrt(n); i++) if (i*i <= n) tong -= i*i;

	cout << n*(n + 1)/2 + tong;
	return 0;
}