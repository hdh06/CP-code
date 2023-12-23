#include <bits/stdc++.h>

using namespace std;

ofstream fo("LOG.txt");

void out(bool c){
	fo << (c?"■ ":"□ ");
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	double r; int n;
	cin >> n >> r;

	bool d[101][101] = {};
	
	int dem = 0, dem2 = 0;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++){
			int g = n - i, h = n - j;
			int dis = g*g + h*h, dis2 = (g - 1)*(g - 1) + (h - 1)*(h - 1);
			if (dis >= r*r && r*r > dis2) d[i][j] = true;
		}
	}

	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++){
			out(d[i][j]);
		}
		for (int j = 0; j <= n - 1; j++){
			out(d[i][n - 1 - j]);
		}
		fo << endl;
	}
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++){
			out(d[n - 1 - i][j]);
		}
		for (int j = 0; j <= n - 1; j++){
			out(d[n - 1 - i][n - 1 - j]);
		}
		fo << endl;
	}
	return 0;
}

 // fo << "■ ";
	// 		else fo << "□ ";