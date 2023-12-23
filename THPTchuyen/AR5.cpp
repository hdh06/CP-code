#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int dem = 0;
	while(n--){
		long long t; cin >> t;
		dem += (t > 0 && t == (long long)sqrt(t)*(long long)sqrt(t));
	}	
	cout << dem;
	return 0;
}