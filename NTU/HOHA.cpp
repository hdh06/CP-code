#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int dem = 0;
	for (int i = 1; i <= sqrt(n); i++) if (n % i == 0){
		dem += i + (n / i == i? 0 : n/i);
	}	


	cout << (dem == 2*n? "YES" : "NO"); 
	return 0;
}