#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	int five = 0, zero = 0;
	while(n--){
		int temp; cin >> temp;
		if (temp == 5) five ++;
		else zero ++;
	}

	if (zero == 0){
		cout << -1;
		return 0;
	}
	five /= 9;
	five *= 9;
	if (five == 0) cout << 0;
	else{
		while (five --) cout << 5;
		while (zero --) cout << 0;
	}
	return 0;
}
