#include <bits/stdc++.h>

using namespace std;

long long const P[] = {0, 1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000}
;
int main(){
	int n; cin >> n;
	cout << P[n];
	return 0;
}