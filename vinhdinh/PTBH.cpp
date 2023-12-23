#include <bits/stdc++.h>

using namespace std;

int main(){
	long double a, b, c; 
	cin >> a >> b >> c;	

	long double delta = b*b - 4*a*c;
	cout << setprecision(2) << fixed;
	if (delta < 0){
		cout << "VO NGHIEM";
	}
	else 
	if (delta == 0){
		cout << "PT CO NGHIEM KEP" << endl << "X = ";
		cout << -b/(2*a);
	}
	else 
	if (delta > 0){
		cout << "PT CO HAI NGHIEM" << endl;
		cout << "X1 = " << (-b + sqrt(delta))/(2*a) << endl;
		cout << "X2 = " << (-b - sqrt(delta))/(2*a);
	}
	return 0;
}