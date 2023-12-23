#include <bits/stdc++.h>

using namespace std;

int const N = 1e1;
bool sang[N] = {1, 1};

vector<int> ans;

void init(){
	for (int i = 2; i < N; i++) if (!sang[i]){
		for (int j = i * i; j < N; j+=i) sang[j] = true;
		ans.push_back(i);
	}
}

int main(){
	init();
	int n;
	cin >> n;
	if (n % 2 == 0){
		int x = n + 1;
		for (int i = 1; i < ans.size() && ans[i] <= n; i++){
			while (x % ans[i] == 0){
				x /= ans[i];
			}
		}
		if (x == 1) cout << "YES";
		else cout << "NO";
	}	
	else{
		cout << "YES";
	}
	return 0;
}