#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int main(){
	int n;
	cin >> n;

	vector<ii> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

	sort(arr.begin(), arr.end(), [](ii a, ii b){return a[1] < b[1];});

	int dem = 0, curr = 0;
	for (int i = 0; i < n; i++){
		if (arr[i][0] >= curr){
			dem++;
			curr = arr[i][1];
		}
	}	

	cout << dem;
	return 0;
}