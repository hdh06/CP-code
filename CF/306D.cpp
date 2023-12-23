#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	cout << setprecision(3) << fixed;
	double d = (double)360 / (double)n;
	for (int i = 0; i < n; i++){
		double x = (double)i * d;
		cout << cos(x) << " " << sin(x) << "\n"; 
	}	
	return 0;
}