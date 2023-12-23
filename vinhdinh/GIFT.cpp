#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t --){
		unsigned long long x, y, u, v, t;
		cin >> x >> y >> u >> v >> t;
		// unsigned long long arr[] = {x*u + y*v, u*x + u*y + t*y, v*x + v*y + t*x};
		// cout << *min_element(arr, arr + 3) << endl;
		if (u + t < v){
			cout << u*x + u*y + t*y;
		}
		else if (v + t < u){
			cout << v*x + v*y + t*x;
		}	
		else cout << x*u + y*v;
		cout << endl;
	}
	return 0;
}