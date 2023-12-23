#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;

	long long ucln;
	cin >> ucln;

	for(int t = n - 1;t--;){
		long long temp;
		cin >> temp;
		ucln = __gcd(ucln, temp);
	}	

	cout << ucln*n;
	return 0;
}