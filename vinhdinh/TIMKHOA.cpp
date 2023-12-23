#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int GCD;
	cin >> GCD; n--;

	while(n --){
		int temp;
		cin >> temp;
		GCD = __gcd(GCD, temp);
	}

	cout << GCD;
	return 0;
}