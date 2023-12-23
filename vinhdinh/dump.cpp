#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int a = 0, b = 0;
	while(n --){
		int t;
		cin >> t;
		a += (t == 100);
		b += (t == 200);
	}	

	if (a % 2 != 0){
		cout << "NO";
		return 0;
	}
	if (b % 2 != 0 && a < 2){
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}