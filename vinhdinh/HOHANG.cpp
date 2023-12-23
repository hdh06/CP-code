#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b; 
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		cout << (a == b) << endl;
	}
	return 0;
}