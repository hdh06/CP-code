#include <bits/stdc++.h>

using namespace std;

bool check(int n){
	if ((int)sqrt(n)*(int)sqrt(n) == n) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	for (int i = 3; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			if (check(i * i + j * j)) cout << i << " " << j << endl;
		}
	}
	return 0;
}