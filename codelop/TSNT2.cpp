#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int const N = 1001;
	int temp;
	int i = 2;
	while(n > 1){
		if (n % i == 0) {
			temp ++;
			n /= i;
		}
		else{
			if (temp != 0) cout << i << "^" << temp << " * ";
			temp = 0;
			i++;
		}
	}
	cout << i << "^" << temp;
	return 0;
}