#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	for (int i = 0; i < 3; i++){
		for (int j = 1; j <= n - i; j++)
			cout << '#';
		cout << endl;
	}	
	return 0;
	
}