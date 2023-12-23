#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

	int dem = 0;
	for (int i = 1; i <= sqrt(a); i++) if (a % i == 0){
		if (b % i == 0) dem++;
		if (b % (a / i) == 0) dem++;
	}	

	cout << dem;
	return 0;
}