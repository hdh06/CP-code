#include <bits/stdc++.h>

using namespace std;

vector<int > arr;

// bool comp(pair<int, int> p1/*a*/, pair<int, int> p2/*b*/){
// 	if (p1.first > p2.frist) return rt;
//     if (p1.first < p2.frist) return !rt;
// 	if (p1.second < p2.second) return rt;
// 	if (p2.second < p1.second) return !rt;
// }

bool comp(int a, int b){
	return arr[a] < arr[b];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d, a, b;
	cin >> n >> d >> a >> b;
	vector<int> st(n + 1);
	vector<bool> visited(n + 1);
	arr.assign(n + 1, 0);

	for (int i = 1; i <= n; i++){
		int x , y;
		cin >> x >> y;
		arr[i] = a*x + b*y;
		st[i] = i;
	}

	sort(st.begin() + 1, st.end(), comp);
	int tong = 0;
	for (int i = 1; i <= n; i++){
	    int index = st[i];
		d -= arr[index];
		if (d >= 0){
			tong ++;
			visited[index] = true;
		}
		else break;
		// cout << arr[index] << endl;
	}

	cout << tong << endl;

	for (int i = 1; i <= n; i++){
		if (visited[i] == true) cout << i << " ";
	}

	return 0;
}