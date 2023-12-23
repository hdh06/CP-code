#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n + 2, 0);	

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int max_i = 0, max_j = 0, max_area = 0;

	for (int i = 1, j = n; i < j;){
		int maxAij = (j - i)*min(arr[i], arr[j]);
		if (max_area < maxAij){
			max_area = maxAij;
			max_i = i;
			max_j = j;
		}
		if (arr[i] < arr[j]) i++;
		else if (arr[i] > arr[j]) j--;
		else if (arr[i] == arr[j]) i++, j--;
	}

	cout << max_i << " " << max_j;
	return 0;
}