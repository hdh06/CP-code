#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int arr[N];
int sum;

bool dequy(int i, int s){
	if (s == sum - s) return true;
	return dequy(i - 1, s - arr[i]) | dequy(i - 1, s);
}

int main(){
	int n;
	cin >> n;	

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if(dequy(n, sum)) cout << "YES";
	else cout << "NO";
	return 0;
}