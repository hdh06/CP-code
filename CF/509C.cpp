#include <bits/stdc++.h>
#include <debug.h>

using namespace std;

int const N = 301;

char chr(int x){return x + '0';}
int num(char x){return x - '0';}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;	
	int arr[N];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	string brr[N];
	while (arr[1] - 9 >= 0) brr[1] = brr[1] + '9', arr[1] -= 9;
	if (arr[1] > 0) brr[1] = chr(arr[1]) + brr[1];

	for (int i = 2; i <= n; i++){
		for (int j = 0; j < brr[i - 1].size(); j++){
			if (arr[i] - num(brr[i - 1][j]) >= 0)
				brr[i] = brr[i] + brr[i - 1][j], arr[i] -= num(brr[i - 1][j]);
			else brr[i] += chr(arr[i]), arr[i] = 0;
		}
		// cerr << "->" << brr[i] << "\n";
		for (int k = brr[i].size() - 1; k >= 0; k--){
			if (arr[i] >= '9' - brr[i][k])
				arr[i] -= '9' - brr[i][k], brr[i][k] = '9';
			else brr[i][k] += arr[i], arr[i] = 0;
		}
		if (arr[i]){
			while (arr[i] - 9 >= 0)
				arr[i] -= 9, brr[i] = '9' + brr[i];
			if (arr[i]) brr[i] = chr(arr[i]) + brr[i];
		}
		if (brr[i] > brr[i - 1]) continue;
		brr[i] = '0' + brr[i];
		int j = brr[i].size() - 1;
		while (brr[i][j] == '0') j--;
		int z = j - 1;
		while (brr[i][z] == '9') z--;
		brr[i][z]++;
		brr[i][j]--;
		sort(brr[i].begin() + z + 1, brr[i].end());
		if (brr[i][0] == '0') brr[i].erase(0, 1);
	}	

	for (int i = 1; i <= n; i++)
		cout << brr[i] << "\n";
	debug(n);
	return 0;
}