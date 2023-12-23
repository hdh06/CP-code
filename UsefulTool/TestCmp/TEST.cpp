#include <bits/stdc++.h>

using namespace std;

ifstream inp1("inp1.inp");
ifstream inp2("inp2.inp");
ifstream test("case.inp");
ofstream out("out.txt");

int main(){
	string a, b, t;
	getline(test, t);
	inp1 >> a; inp2 >> b; getline(test, t);
	int dem = 1;
	while(a != "-1"){
		if (a != b){
			out << "Diff on line " << dem << ": [" << a << "] != [" << b << "] - INPUT: "<< t << "-" <<"\n";
		}
		inp1 >> a; inp2 >> b; getline(test, t);
		dem++;
	}
	return 0;
}