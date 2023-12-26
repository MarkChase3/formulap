#include <bits/stdc++.h>

using namespace std;

int main(){
        string inp;
        vector<pair<int, string>> tests;
        tests.push_back(make_pair(8, "YES"));
        tests.push_back(make_pair(7, "NO"));
        tests.push_back(make_pair(2, "NO"));
        tests.push_back(make_pair(1, "NO"));
        tests.push_back(make_pair(10, "YES"));
        tests.push_back(make_pair(11, "NO"));
        tests.push_back(make_pair(1000000000, "YES"));
        tests.push_back(make_pair(1000000000-1, "NO"));
        for(int i = 0; i < tests.size(); i++){
                cout << tests[i].first << endl;
                cin >> inp;
                if(tests[i].second != inp){
                        cerr << i*(100/tests.size()) << inp;
                        return 0;
                }
                inp = "";
        }
        cerr << 100;
        return 0;
}
