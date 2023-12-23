#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "sub3";
string const SOL = "sol";
string const FILE_NAME = "fourking";
string const C_VERSION = "17";
int const N = 100;
int const L = 252, R = 252;

void compile(string file){
	const string com = "g++ -std=c++" + C_VERSION + " " + file + ".cpp -o " + file; 
	system(com.c_str()); 
}

void run(string file){
	const string com = "./" + file;
	system(com.c_str()); 
}

void redir(int x){
	ifstream in("fourking.inp");
	string com = "test"; 
	com += (char)(x/100 + '0');
	com += (char)((x%100) / 10 + '0');
	com += (char)(x%10 + '0');
	com += ".inp";
	cout << com << "\n";
	ofstream out(com);
	int t; in >> t;
	out << t << "\n";
	in.ignore();
	while (t--){
		string s; getline(in, s);
		out << s << "\n";
	}
}

int main(){
	compile(BRUTE);
	compile(SOL);
	compile("gen");

	int dem = 0;
	for (int t = L; t <= R; t++){
		clock_t s1, e1, s2, e2;
		cout << "TESTCASE #" << t << ":\n";

		run("gen");

		run(BRUTE);
		ifstream out1(FILE_NAME + ".out");
		string ans1; getline(out1, ans1);

		run(SOL); 
		ifstream out2(FILE_NAME + ".out");
		string ans2; getline(out2, ans2);

		ifstream inp(FILE_NAME + ".inp");

		string in; inp >> in; inp >> in;

		cout << "status: " << (ans1 == ans2? "AC\n" : "WA\n");
		cout << "[inp] " << in << "\n";
		cout << "[brute] " << ans1 << " [sol] " << ans2 << "\n";

		if (ans1 != ans2) dem++;
		redir(t);
	}

	cout << "===== AC:" << N - dem << " / WA:" << dem << " =====\n";
	return 0;
}