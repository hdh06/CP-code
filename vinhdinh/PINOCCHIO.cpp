#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int ucln;
	cin >> ucln;
	n--;
	while (n--){
		int temp;
		cin >> temp;
		ucln = __gcd(ucln, temp);
	}	

	cout << ucln;
	return 0;
}