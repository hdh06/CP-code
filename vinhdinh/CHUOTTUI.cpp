#include <bits/stdc++.h>

using namespace std;

int main(){
	long long x1, v1, x2, v2;
	cin >> x1 >> v1 >> x2 >> v2;

	if ((x1 - x2)*(v2-v1) > 0 && (x1 - x2) % (v2 - v1) == 0){
		cout << "YES";
	}	
	else cout << "NO";
	return 0;
}