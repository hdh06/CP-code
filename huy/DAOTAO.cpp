#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr.begin(), arr.end(), greater<int>());
	int dem = 0, blank = 0;
	while (dem != sum){
		int i = 0;
		while(arr[i] != 0) i++;
		if (dem != sum && ar)

	}

	cout << dem;
	return 0;
}

//