#include <bits/stdc++.h>

using namespace std;

vector<int> p;

void dequy(int n){
	if (n == 0){
		for (auto x: p) cout << x;
		cout << "\n";
		return;
	}
	for (int i = 0; i <= 1; i++){
		p.push_back(i);
		dequy(n - 1);
		p.pop_back();
	}
}

int main(){
	int n;
	cin >> n;	
	dequy(n);
	return 0;
}