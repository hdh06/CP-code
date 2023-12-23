#include <bits/stdc++.h>

using namespace std;


int main(){
	int n; cin >> n;

	int tmp = n;
	int maxx = 1;
	for (int i = 2; i * i <= tmp; i ++){
		if (tmp % i == 0) maxx = max(maxx, i);
		while (tmp % i == 0) tmp /= i;
	}

	if (tmp > 1) maxx = max(maxx, tmp);

	cout << n / maxx;
	return 0;
}