#include <bits/stdc++.h>

using namespace std;

int n;

string p;

int dem(int i, bool k, int pre){
	if (i == n + 1){
 		return 1;
	}

	int tong = 0;

	tong += dem(i + 1, k, 0);

	if (pre != 0)
		tong += dem(i + 1, k, 1);
	else if (!k)
		tong += dem(i + 1, 1, 1);
	return tong;
}

void dequy(int i, bool k){
	if (i == n + 1){
		cout << p << '\n';
 		return;
	}

	p = p + '0';
	dequy(i + 1, k);
	p.erase(p.end() - 1);
		
	int pre = (p.empty()? -1 : p.back() - '0');

	p = p + '1';
	
	if (pre != 0)
		dequy(i + 1, k);
	else if (!k)
		dequy(i + 1, 1);
	
	p.erase(p.end() - 1);
}

int main(){
	cin >> n;
	cout << dem(1, 0, -1) << endl;
	dequy(1, 0);
	return 0;
}