#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, tong = 0;
	while(cin >> a >> b){
		tong += a*b;
	}	
	cout << "Tong thu: " << tong;
	return 0;
}