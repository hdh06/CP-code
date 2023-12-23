#include <bits/stdc++.h>

using namespace std;

bool solve(string L){
	string R = L;
	reverse(R.begin(), R.end());

	for (int i = 1; i < L.size(); i++){
		if (abs(L[i] - L[i - 1]) != abs(R[i] - R[i - 1])) return false;
	}	
	return true;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		string L;
		cin >> L;
		if (solve(L)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}	