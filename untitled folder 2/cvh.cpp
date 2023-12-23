#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point{
	ll x, y;
};

int const N = 1e5 = 1;

ll cross(point A, point B){
	return A.x * B.y - B.x * A.y;
}

point vtc(point A, point B){
	return {B.x - A.x, B.y - A.y};
}


int main(){
	int n; cin >> n;
	point arr[N];
	for (int i = 1; i <= n; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr + 1, arr + n + 1, [](point a, point b){
		return {a.x, a.y} < {b.x, b.y};
	});


	return 0;
}