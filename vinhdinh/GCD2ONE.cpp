#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	int GCD = 0;

	while(n--){
		int temp; cin >> temp;
		GCD = gcd(GCD, temp);
	}	
	if (GCD != 1) cout << -1;
	else cout << 0;
	return 0;
}