#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; 
	cin >> t; 

	while(t--){
		int n, m;
		cin >> n >> m;

		if (n % m == 0) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}