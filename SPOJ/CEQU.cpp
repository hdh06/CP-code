#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	for (int i = 1; i <= t; i++){
		cout << "Case " << i << ": ";
		int a, b, c; cin >> a >> b >> c;
		if (c % __gcd(a, b) == 0){
			cout << "Yes\n";
		}else cout << "No\n";
	}	
	return 0;
}