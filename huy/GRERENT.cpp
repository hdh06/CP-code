#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i].first;
	}

	for (int i = 0; i < n; i++){
		cin >> arr[i].second;
	}

	sort(arr)
	return 0;
}