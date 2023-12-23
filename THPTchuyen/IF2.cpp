#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b; cin >> a >> b;	
	if (b == 0) cout << -1;
	else if (a % b == 0) cout << "YES";
	else cout << "NO";
	return 0;
}