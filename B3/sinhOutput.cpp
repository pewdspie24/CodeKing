#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//rieng sinh output thi ko can sua gi ca
int main () {
    int N = 15;
    string solve;
    cin >> solve;
    for (int i = 0; i < N; i++) {
        string s;
        ostringstream convert;
        convert << i+1;
        s=convert.str();
        
        string output=solve+"<test/"+s+".in"+">test/"+s+".out";
        const char *command = output.c_str();
        system(command);
        cout << "Created output test:" << i+1 << endl;
    }
    return 0;
}
