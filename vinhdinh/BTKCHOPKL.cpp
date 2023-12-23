#include <bits/stdc++.h>

using namespace std;

vector<int> t;
vector<int> arr;
int n, k; 
bool vis[10];
int dem = 0;

void dequy(int x, int ik){
	if (ik == 0){
		for (auto c: t){
			cout << c << " ";
		}
		cout << endl;
		dem++;
		return;
	}

	for (int i = 1; i <= n; i++) if (!vis[i]){
		t.push_back(arr[i]);
		vis[i] = true;
		dequy(i, ik - 1);
		vis[i] = false;
		t.pop_back();
	}
}

int main(){
	cin >> n >> k;
	arr.assign(n + 1, 0);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	dequy(0, k);
	cout << dem;
	return 0;
}
