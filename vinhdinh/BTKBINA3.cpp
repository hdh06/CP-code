#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int n;

int dequy_dem(int i){
	if (i == n + 1){
		return 1;
	}

	int tong = 0;
	for (int x = 0; x <= 1; x++){
		if (!p.empty() && !(p.back() == 1 && x == 1)){
			p.push_back(x);
			tong += dequy_dem(i + 1);
			p.pop_back();
		}
		if (p.empty()){
			p.push_back(x);
			tong += dequy_dem(i + 1);
			p.pop_back();
		}
	}
	return tong;
}

void dequy(int i){
	if (i == n + 1){
		for (auto x: p) cout << x;
		cout << endl;
		return;
	}

	for (int x = 0; x <= 1; x++){
		if (!p.empty() && !(p.back() == 1 && x == 1)){
			p.push_back(x);
			dequy(i + 1);
			p.pop_back();
		}
		if (p.empty()){
			p.push_back(x);
			dequy(i + 1);
			p.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cout << dequy_dem(1) << endl;
	dequy(1);		
	return 0;
}