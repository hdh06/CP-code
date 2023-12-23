#include <bits/stdc++.h>

using namespace std;

int calc(int n){
	int dem = 0;
	for (int i = 1; i <= sqrt(n); i++) if (n % i == 0){
		dem += i + (n / i == i? 0 : n/i);
	}	
	return dem - n;
}

int main(){
	int a, b; cin >> a >> b;
	if (a == calc(b) && b == calc(a)) cout << "YES";
	else cout << "NO";
	return 0;
}