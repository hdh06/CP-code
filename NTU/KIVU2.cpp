#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define vi vector<int>

int n;

int xepcap(vi a, vi b){
	a.resize(a.size());
	b.resize(b.size());
	int dem = 0;
	for (int i = 0, j = 0; i < a.size() && j < b.size();){
		if (abs(a[i]) > b[j]){
			i++;
			j++;
			// cout << a[i] << " " << b[j] << endl;
			dem++;
		}
		else{
			i++;
		}
	}
	return dem;
}

int main(){
	cin >> n;
	vi a,b,c,d;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		if (temp < 0) a.push_back(temp);
		else b.push_back(temp);
	}

	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		if (temp < 0) c.push_back(temp);
		else d.push_back(temp);
	}

	sort(all(a),greater<int>());sort(all(c),greater<int>());
	sort(all(b));sort(all(d));

	cout << xepcap(a, d) + xepcap(c, b);
	return 0;
}