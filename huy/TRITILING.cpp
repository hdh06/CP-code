#include <bits/stdc++.h>

using namespace std;

int const N = 31;

int db[N][8] = {};

void count(int n){
	 db[0][7] = 1;
	 for (int i = 1; i <= n; i++){
	 	db[i][0] += db[i-1][7];

	 	db[i][1] += db[i-1][6];

	 	db[i][2] += db[i-1][5];

	 	db[i][3] += db[i-1][4];
	 	db[i][3] += db[i-1][7];

	 	db[i][4] += db[i-1][3]; 

	 	db[i][5] += db[i-1][2];

	 	db[i][6] += db[i-1][7];
	 	db[i][6] += db[i-1][1];

	 	db[i][7] += db[i-1][0];
	 	db[i][7] += db[i-1][3];
	 	db[i][7] += db[i-1][6];
	 }
}

int main(){
	count(30);
	int temp;
	cin >> temp;
	while (temp != -1){
		cout << db[temp][7] << endl;
		cin >> temp;
	}
	return 0;
}