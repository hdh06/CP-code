#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

int const N = 2e5 + 1;

int main(){
	int n; cin >> n;
	iii arr[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = i;
	}

	sort(arr + 1, arr + n + 1, [](iii a, iii b){
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	bool isIn[N] = {};
	bool isOut[N] = {};

	multiset<int> ms;
	for (int i = 1; i <= n; i++) ms.insert(arr[i][1]);

	for (int i = 1; i <= n; i++){
		ms.erase(ms.lower_bound(arr[i][1]));
		if (ms.size() > 0 && arr[i][1] >= *ms.begin()) 
			isIn[arr[i][2]] = 1;
	}

	for (int i = 1; i <= n; i++){
		if (ms.size() > 0 && arr[i][1] <= *ms.rbegin()) 
			isOut[arr[i][2]] = 1;
		ms.insert(arr[i][1]);
	}

	for (int i = 1; i <= n; i++) cout << isIn[i] << " \n"[i == n];
	for (int i = 1; i <= n; i++) cout << isOut[i] << " \n"[i == n];	
	return 0;
}