#include <bits/stdc++.h>

using namespace std;

int main(){
	long long arr[10];
	memset(arr, 0x3f, sizeof arr);
	cout << LLONG_MAX << "\n";
	for (int i = 1; i <= 9; i++)
		cout << bitset<30>(arr[i]) << " ";
	return 0;
}