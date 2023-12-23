#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int main(){
	int n, p;
	cin >> n >> p;

	vector<ii> arr(n + 1);

	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		arr[i] = {temp, i};
	}	

	sort(arr.begin() + 1, arr.end());

	for (int i = 1; i <= n; i++){
		if (arr[i][1] == p){
			cout << i;
			return 0;
		}
	}
	return 0;
}