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
//        long long M=Create(0,1000);
//        long long N=Create(1000,100000);
        long long B=Create(1,10);
		long long C=Create(1,10);
//		fout<<M<<' '<<N<<endl;
		// for(int i = 0; i < B; i++)
		// {
		// 	long long A=Create(0,100);
		// 	for(int j = 0; j < A; j++){
		// 		long long C = Create(97,122);
		// 		char c = C;
		// 		fout<<c;
		// 		i++;
		// 	}
		// 	long long M = Create(1,7);
		// 	for(int j = 0; j < M; j++){
		// 		long long N = Create(0,9);
		// 		fout<<N;
		// 		i++;
		// 	}
		// }
		fout<<B<<" "<<C<<"\n";
    }
}
//sinh test vua
void createTest2(ofstream & fout) {
    int T=Create(10,100);
    fout << T<<endl;
    while(T--)
    {
//        long long M=Create(0,1000);
//        long long N=Create(1000,100000);
        long long B=Create(1,10);
		long long C=Create(10,18);
//		fout<<M<<' '<<N<<endl;
		// for(int i = 0; i < B; i++)
		// {
		// 	long long A=Create(0,30);
		// 	for(int j = 0; j < A; j++){
		// 		long long C = Create(97,122);
		// 		char c = C;
		// 		fout<<c;
		// 		i++;
		// 	}
		// 	long long M = Create(1,7);
		// 	for(int j = 0; j < M; j++){
		// 		long long N = Create(0,9);
		// 		fout<<N;
		// 		i++;
		// 	}
		// }
		fout<<B<<" "<<C<<"\n";
	}
}
//sinh test lon
void createTest3(ofstream & fout) {
    int T=Create(10,100);
    fout << T<<endl;
    while(T--)
    {
        long long B=Create(1,3);
		long long C=Create(20,30);
        // fout<<M<<endl;
        // for(int i = 0; i < M; i++)
		// {
		// 	long long A=Create(10,100);
		// 	fout <<A<<' ';
		// }
		fout<<B<<" "<<C<<"\n";
    }
}

int main () {
	srand(time(NULL));
    int N = 10;
    for (int i = 0; i < N; i++) {
        string s;
        ostringstream convert;
        convert << i+1;
        s=convert.str();
        string input = "test/"+ s + ".in";
        ofstream fout(input.c_str());
        if(i<5)
        createTest(fout);
        else if(i<8) createTest2(fout);
        else createTest3(fout);
        fout.close();
        cout << "Created test:" << i+1 << endl;
    }
    return 0;
}
