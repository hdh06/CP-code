#include <bits/stdc++.h>

using namespace std;

bool primeCheck(int n){
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;
}

bool uocCheck(vector<int> path, int x){
	for (auto i: path) if (i % x == 0) return true;
	return false;
}

int main(){
	int n;
	cin >> n;

	vector<int> path;

	path.push_back(n);

	for (int i = n - 1; i >= 1; i--){
		if (primeCheck(i) || uocCheck(path, i)) path.push_back(i);
	}	

	cout << path.size() << endl;
	for (auto x: path) cout << x << " ";
	return 0;
}