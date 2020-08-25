#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
typedef pair<long long, long long> pt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Create(long long l, long long r) { 
    return rng() % (r - l + 1) + l;
}
//sinh test nho
void createTest(ofstream & fout) {
    int T=Create(1,10);
    fout << T<<endl;
    while(T--)
    {
        long long M=Create(1,10);
//        long long N=Create(1,M);
        for(int i = 0; i < M; i++){
            long long Q = Create(97,122);
            fout<<Q;
        }
//        for(int i = 0; i < M; i++)
//		{
//			long long A=Create(100000,10000000);
//			fout <<A<<' ';
//		}
		fout<<"\n";
    }
}
//sinh test vua
void createTest2(ofstream & fout) {
    int T=Create(10,100);
    fout << T<<endl;
    while(T--)
    {
        long long M=Create(10,100);
//        long long N=Create(1,M);
        for(int i = 0; i < M; i++){
            long long Q = Create(97,122);
            fout<<Q;
        }
//        for(int i = 0; i < M; i++)
//		{
//			long long A=Create(100000,10000000);
//			fout <<A<<' ';
//		}
		fout<<"\n";
    }
}
//sinh test lon
void createTest3(ofstream & fout) {
    int T=Create(10,100);
    fout << T<<endl;
    while(T--)
    {
        long long M=Create(100,1000);
//        long long N=Create(1,M);
        for(int i = 0; i < M; i++){
            long long Q = Create(97,122);
            fout<<Q;
        }
//        for(int i = 0; i < M; i++)
//		{
//			long long A=Create(100000,10000000);
//			fout <<A<<' ';
//		}
		fout<<"\n";
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
