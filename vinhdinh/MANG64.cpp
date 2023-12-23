#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	for (int i = 2; i <= 2 + n - 1; i++){
		for (int j = i; j <= i + n - 1; j++) cout << j << " \n"[j == i + n - 1];
	}
	return 0;
}