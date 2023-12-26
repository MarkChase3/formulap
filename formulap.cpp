#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
	if(argc > 2){
		string cmd = argv[1];
		if(cmd == "drive"){
			cout << "CACHING..." << endl;
			system(("cp problems/"+string(argv[2])+".cpp tmp/checker.cpp").c_str());
			system(("cp solutions/"+string(argv[2])+".cpp tmp/answer.cpp").c_str());
			cout << "COMPILING..." << endl;
			system("g++ -o tmp/checker tmp/checker.cpp");
			system("g++ -o tmp/answer tmp/answer.cpp");
			cout << "SETTING UP..." << endl;
			FILE *f = fopen("p", "w");
			fprintf(f, " ");
			fclose(f);
			f = fopen("tmp/p", "r");
			char * pc = (char*)malloc(sizeof(char)*20);
			fgets(pc, 10, f);
			int j = 1;
			string prevp = "";
			string out = "";
			string str;
			while(string(pc) != prevp){
				if(prevp != "")cout << "STARTING TEST " << j-1 << "..."<< endl;
				system(("touch tmp/txt; echo \""+out+"\" > tmp/txt; tmp/checker < tmp/txt > tmp/i 2> tmp/p;").c_str());

				ifstream in("tmp/i");
				for (int i = 0; i < j-1; ++i) {
					in.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				in >> str;

				system(string("touch tmp/txt; echo \""+str+"\" > tmp/txt; tmp/answer < tmp/txt > tmp/o;").c_str());

				in = ifstream("tmp/o");
				string str2;
				in >> str2;
				out += ' '+str2;

				fclose(f);
				f = fopen("tmp/p", "r");
				prevp = string(pc);
				fgets(pc, 10, f);

				if(prevp != string(pc) and j > 1)cout << "TEST " << j-1 << " PASSED..." << endl;

				j++;
			}
			
			fclose(f);
			if(prevp == "0")cout << "TEST 0 FAILED\nWRONG ANSWER\n";
			else if(prevp != "100")cout << "TEST " << j-2 << " FAILED"<< "\nPARCIAL\n" << out << str;
			else cout << "ALL TESTS PASSED\nACCEPTED\n";
		}
	}
}
