#include <bits/stdc++.h>

using namespace std;

long long s;

bool dequy(long long n){
	if (n > s) return false;
	if (n == s) return true;
	return dequy(n*10) | dequy(n * 20);
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> s;

		if (dequy(1)) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0;
}