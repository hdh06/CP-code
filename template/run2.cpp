#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "";
string const SOL = "";
string const NAME = "";
string const C_VERSION = "17";
int const N = 100;

void compile(string file){
	const string com = "g++ -std=c++" + C_VERSION + " " + file + ".cpp -o " + file; 
	system(com.c_str()); 
}

void run(string file){
	const string com = "./" + file;
	system(com.c_str()); 
}

int main(){
	compile(BRUTE);
	compile(SOL);
	compile("gen");

	for (int t = 1; t <= N; t++){
		cout << "TESTCASE #" << t << ": ";

		run("gen");
		run(BRUTE); 
		run(SOL); 

		string com = "diff -w " + NAME + ".ans " + NAME + ".out";
		if (system(com.c_str())){
			cout << "WA\n";
			return 0;
		}else cout << "AC\n";
	}
	cerr << "Done. All gud."
	return 0;
}