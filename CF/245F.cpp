#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int num(char c){
	return c - '0';
}

typedef long long ll;

vector<int> g[32][13];

string stfy(int x){
	string c;
	c += (x / 10 + '0');
	c += (x % 10 + '0');
	return c;
}

void print(int month, int day, int hour, int min, int sec){
	cout << "2012-" << stfy(month) << "-" << stfy(day) << " " << stfy(hour) << ":" << stfy(min) << ":" << stfy(sec) << "\n";
}
				//  0 	1 	2 	3 	4 	5 	6 	7 	8 	9 	10 	11 	12
int end_day[13] = {222, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int n, m; cin >> n >> m; cin.ignore();
	string x;
	while (getline(cin, x)){
		int day = num(x[8]) * 10 + num(x[9]);
		int month = num(x[5]) * 10 + num(x[6]);
		int hour = num(x[11]) * 10 + num(x[12]);
		int min = num(x[14]) * 10 + num(x[15]);
		int second = num(x[17]) * 10 + num(x[18]);

		int sec = second + min * 60 + hour * 3600;

		g[day][month].push_back(sec);
		if (g[day][month][0] <= sec - n + 1){
			cerr << x << "OK\n";
			int k = lower_bound(all(g[day][month]), sec - n + 1) - g[day][month].begin();
			if (g[day][month].size() - k >= m){
				print(month, day, hour, min, second);
				return 0;
			}
		}else{
			if (g[day][month].size() >= m){
				print(month, day, hour, min, second);
				return 0;
			}
			int pday = day - 1;
			int pmonth = month;
			if (day < 0){
				if (month > 1) pday = end_day[--pmonth];
				else continue;
			}

			if (g[pday][pmonth].size() == 0) continue;

			int k = lower_bound(all(g[pday][pmonth]), 24 * 60 * 60 + sec - n + 1) - g[pday][pmonth].begin();
			if (g[pday][pmonth].size() - k + g[day][month].size() >= m){
				print(month, day, hour, min, second);
				return 0;
			}
		}
	}	
	cout << "-1\n";
	return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 0 1 2 - M M - D D _   H H  :  M  M  :  S  S  :  MESSAGE
*/