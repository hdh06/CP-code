#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<ll, 2> ii;

int const N = 5001;

ii arr[N];

ll area(int x, int y, int z){
	ii a = arr[x], b = arr[y], c = arr[z];
	return abs(a[1]*(b[0] - c[0]) + b[1]*(c[0] - a[0]) + c[1]*(a[0] - b[0]));
}

int main(){
	int n; ll s; cin >> n >> s;

	int a = 1, b = 2, c = 3;

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			if (area(i, b, c) > area(a, b, c)) a = i;
			if (area(a, i, c) > area(a, b, c)) b = i;
			if (area(a, b, i) > area(a, b, c)) c = i;
		}
 	}

 	ii d = arr[a], e = arr[b], f = arr[c];
 	cout << d[0] - e[0] + f[0] << " " << d[1] - e[1] + f[1] << endl;
 	cout << d[0] + e[0] - f[0] << " " << d[1] + e[1] - f[1] << endl;
 	cout <<-d[0] + e[0] + f[0] << " " <<-d[1] + e[1] + f[1] << endl;
	return 0;
}

// fun fact: https://codeforces.com/contest/682/submission/155078301
/*
bool flag = 1;
	while (flag){
		flag = 0;
		for (int i = 1; i <= n; i++){
			if (area(i, b, c) > area(a, b, c)) a = i, flag = 1;
			if (area(a, i, c) > area(a, b, c)) b = i, flag = 1;
			if (area(a, b, i) > area(a, b, c)) c = i, flag = 1;
		}
 	}
*/