#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int dem = 0;
	while(n < m){
		if (n % 10 >= 5) n += n / 10 + 1;
		else n += n / 10;
		dem++;
	}

	cout << dem;
	return 0;
}