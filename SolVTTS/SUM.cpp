#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	n -= (n % 2 == 0);
	n ++; n/= 2;

	cout << n*n;	
	return 0;
}