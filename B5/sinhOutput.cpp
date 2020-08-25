#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
//rieng sinh output thi ko can sua gi ca
int main () {
    int N = 10;
    string solve;
    cin >> solve;
    double Time=0;
    for (int i = 0; i < N; i++) {
    	double Tmp;
    	clock_t tStart = clock();
        string s;
        ostringstream convert;
        convert << i+1;
        s=convert.str();
        string output=solve+"<test/"+s+".in"+">test/"+s+".out";
        const char *command = output.c_str();
        system(command);
        cout << "Created output test:" << i+1 <<"     ";
        Tmp=(double)(clock() - tStart)/CLOCKS_PER_SEC;
        Time+=Tmp;
    	printf("Time taken in test %d: %.2fs\n",i+1, (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    return 0;
    }
    printf("Total Time: %.2fs\n", Time);
    return 0;
}
