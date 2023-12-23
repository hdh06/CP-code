#include <bits/stdc++.h>

using namespace std;

string const BRUTE = "";
string const SOL = "";
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

void redirect(){
	
}

int main(){
	compile(BRUTE);
	compile(SOL);
	compile("gen");

	for (int t = 1; t <= N; t++){
		cout << "TESTCASE #" << t << ":\n";

		run("gen");
		run(BRUTE); 
		run(SOL); 

		string com = "diff -w " + BRUTE + ".out " + SOL + ".out";
		if (system(com)){
			cout << "status: WA\n";
			return 0;
		}else cout << "status: AC\n";
	}
	return 0;
}