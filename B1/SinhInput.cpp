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
    int T=1;
    // fout << T<<endl;
    while(T--)
    {
        long long M=Create(10,1000);
//        long long N=Create(1,M);
//        long long B=Create(1,10);
		fout<<M<<'\n';
		for(int i = 0; i < M; i++)
		{
			long long A=Create(1,1000000);
			fout <<A<<' ';
		}
        fout<<"\n";
        for(int i = 0; i < M; i++)
		{
			long long A=Create(1,1000000);
			fout <<A<<' ';
		}
		fout<<"\n";
    }
}
//sinh test vua
void createTest2(ofstream & fout) {
    int T=1;
    // fout << T<<endl;
    while(T--)
    {
        long long M=Create(100,10000);
//        long long N=Create(1,M);
//        long long B=Create(1,10);
		fout<<M<<'\n';
		for(int i = 0; i < M; i++)
		{
			long long A=Create(100,1000000000);
			fout <<A<<' ';
		}
        fout<<"\n";
        for(int i = 0; i < M; i++)
		{
			long long A=Create(100,1000000000);
			fout <<A<<' ';
		}
		fout<<"\n";
    }
}
//sinh test lon
void createTest3(ofstream & fout) {
    int T=1;
    // fout << T<<endl;
    while(T--)
    {
        long long M=Create(10000,80000);
//        long long N=Create(1,M);
//        long long B=Create(1,10);
		fout<<M<<'\n';
		for(int i = 0; i < M; i++)
		{
			long long A=Create(100,100000);
			fout <<A<<' ';
		}
        fout<<"\n";
        for(int i = 0; i < M; i++)
		{
			long long A=Create(100,100000);
			fout <<A<<' ';
		}
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
