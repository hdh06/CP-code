#include <bits/stdc++.h>

using namespace std;

int f[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//		   0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int main(){
	int v; cin >> v;
	string n; cin >> n;	
	if (v == 1){
		int tong = 0;
		for (auto x: n) tong += f[x - '0'];
		cout << tong << "\n";
	}
	else{
		int dem = 0;
		for (auto x: n)
			for (int i = 0; i <= 9; i++)
				dem += (i > x - '0' && f[x - '0'] < f[i]);
		cout << dem << "\n"; 
	}
	return 0;
}