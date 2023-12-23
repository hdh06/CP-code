#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef array<int, 3> iii;

int main(){
	int n; cin >> n;	

	iii arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = i;	
	} 

	sort(arr + 1, arr + n + 1);

	priority_queue<array<int, 2> > myque;

	int p[N] = {};

	for (int i = 1; i <= n; i++){
		if (!myque.empty() && -myque.top()[0] < arr[i][0]){
			p[arr[i][2]] = p[myque.top()[1]];
			myque.pop();
		}
		else p[arr[i][2]] = myque.size() + 1;
		myque.push({-arr[i][1], arr[i][2]});
	}

	cout << myque.size() << endl;
	for (int i = 1; i <= n; i++) cout << p[i] << " ";
	return 0;
}