#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int const N = 2e5 + 1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n;	
	cin >> n;

	ii arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i][1] >> arr[i][0];
	
	sort(arr + 1, arr + n + 1);
	
	int m1 = -1, m2 = -1;
	for (int i = 1; i <= n; i++){	
		if (m1 < arr[i][1] && m2 < arr[i][1]){
			if (m1 > m2)
				 m1 = arr[i][0];
			else m2 = arr[i][0];
		}
		else {
			if (m1 < arr[i][1])	m1 = arr[i][0];
			else if (m2 < arr[i][1]) m2 = arr[i][0];
			else{
				cout << "NO";
				return 0;
			}
		}
	}		

	cout << "YES";
	return 0;
}