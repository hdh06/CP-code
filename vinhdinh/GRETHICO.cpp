#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end(), greater<int>());

	int dem = 1, curr = arr[0], curr_p = 0, maxd = 1;;

	for (int i = 1; i < n; i++){
		dem++;
		while (curr > arr[i]*2){
			dem--;
			curr = arr[++curr_p];
		}
		maxd = max(maxd, dem);
	}	

	cout << maxd;
	return 0;
}