#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	arr.push_back(-1);


	int streak = 1, tong = 0;
	for (int i = 1; i < n + 1; i++){
		if (arr[i] != arr[i - 1]){
			if (streak > 1) tong += streak;
			streak = 1;
		}
		else{
			streak++;
		}
	}

	cout << tong;
	return 0;
}