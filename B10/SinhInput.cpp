#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
typedef pair<long long, long long> pt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Create(long long l, long long r) { 
    return rng() % (r - l + 1) + l;
}

map <long long,long long > ABC;
//sinh test nho
// ll a[10000000]
void createTest(ofstream & fout) {
    int T=1;
    while(T--)
    {
        long long B=Create(10,100);
		fout<<B<<" ";
		long long C = 100000;
		while(C > B){
			C=Create(10,100);
		}
		fout<<C;
    }
}
//sinh test vua
void createTest2(ofstream & fout) {
    int T=1;
    while(T--)
    {
        long long B=Create(100,500);
		fout<<B<<" ";
		long long C = 100000;
		while(C > B){
			C=Create(100,500);
		}
		fout<<C;
    }
}
//sinh test lon
void createTest3(ofstream & fout) {
    int T=1;
    while(T--)
    {
        long long B=Create(500,1000);
		fout<<B<<" ";
		long long C = 100000;
		while(C > B){
			C=Create(500,1000);
		}
		fout<<C;
    }
}

int main () {
	srand(time(NULL));
    int N = 15;
    for (int i = 0; i < N; i++) {
        string s;
        ostringstream convert;
        convert << i+1;
        s=convert.str();
        string input = "test/"+ s + ".in";
        ofstream fout(input.c_str());
        if(i<5)
        createTest(fout);
        else if(i<10) createTest2(fout);
        else createTest3(fout);
        fout.close();
        cout << "Created test:" << i+1 << endl;
    }
    return 0;
}
