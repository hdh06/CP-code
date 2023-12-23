#include <bits/stdc++.h>

using namespace std;

int const N = 9e5 + 1;
int const MOD = 998244353;

int n;
int p[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}

	int pos = -1;
	for (int i = 1; i <= n; i++)
		if (p[i] == 1) pos = i;

	if (pos != -1){
		int pre = -1;
		for (int i = 1; i < pos; i++) if (arr[i]){
			if (pre != -1 && arr[pre] < arr[i]){
				cout << 0;
				return 0;
			}
			pre = i;
		}
		pre = -1;
		for (int i = n; i < poss; i--) if (arr[i]){
			if (pre != -1 && arr[pre] < arr[i]){
				cout << 0;
				return 0;
			}
			pre = i;
		}
	}else{

	}
	return 0;
}
