#include <bits/stdc++.h>

using namespace std;

bool check(int n){
	int tong = 0;
	while(n > 0){
		tong += n % 10;
		n /= 10;
	}
	return (tong == 10);
}

int main(){
	int k;
	cin >> k;

	int i = 0;

	for (int j = 0; j < k;i+= (j < k)) if (check(i)) j++;

	cout << i;

	return 0;
}