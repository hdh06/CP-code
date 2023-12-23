#include <bits/stdc++.h>

using namespace std;

int main(){
	double n; 
	cin >> n;
	vector<double> diem(n);
	double tong = 0;
	for(double i = 0; i < n; i++){
			cin >> diem[i];
			tong += diem[i];
	}

	sort(diem.begin(), diem.end());
	int dem;
	for (int i = 0; (double)(tong/n) <= 4.5 && i <= n; i++, dem++){
		tong -= diem[i];
		tong += 5;
		// cout << (double)(tong/n) << endl;
	}
	cout << dem;
	return 0;
}