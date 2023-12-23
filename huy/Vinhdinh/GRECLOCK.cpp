#include <bits/stdc++.h>

using namespace std;

int const nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	int n;
	cin >> n;
	if (n % 2 != 0 && n >= 3){
		cout << 7;
		n -= 3;
	}
	for (int i = 1; i <= n/2; i++){
		cout << 1;
	}
	return 0;
}