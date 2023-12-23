#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	bool arr[1001] = {true};
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		arr[temp] = true;
	}
	for (int i = 1; i < 1001; i++){
		if (arr[i] == false){
			cout << i;
			return 0;
		} 
	}
	if (n == 1000) cout << -1;
	return 0;
}