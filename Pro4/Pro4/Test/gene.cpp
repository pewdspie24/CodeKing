#include<bits/stdc++.h>
#define ld long double
using namespace std;

const int N = 1234567;
int n;
int cnt[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long creat(long long a ,long long b)						
{											
	return (long long)rng() % (b - a + 1) + a;					// Create random number in [a, b]
}

void sinhInput(int numberTest) 
{
//	for (int i = 1; i < 5; i++) 
//	{
//		char fileIn[20];
//		sprintf(fileIn, "%d.in", i);
//		fstream out(fileIn, ios::out);
//		n = 1e5;
//		out << n << endl; 
//		for(int j = 0; j < n; j++){
//			int x = creat(1, 1e2);
//			out << x << " ";
//		}
//        out.close();
//	}
//	for (int i = 5; i < 11; i++) 
//	{
//		char fileIn[20];
//		sprintf(fileIn, "%d.in", i);
//		fstream out(fileIn, ios::out);
//		n = 1e5;
//		out << n << endl; 
//		for(int j = 0; j < n; j++){
//			int x = creat(1e2, 1e4);
//			out << x << " ";
//		}
//        out.close();
//	}
//	for (int i = 11; i < 16; i++)
//	{
//		char fileIn[20];
//		sprintf(fileIn, "%d.in", i);
//		fstream out(fileIn, ios::out);
//		n = 1e5;
//		out << n << endl; 
//		for(int j = 0; j < n; j++){
//			int x = creat(1e4, 1e5);
//			out << x << " ";
//		}
//        out.close();
//	}
	int i = 15;
	char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = 1e5;
		out << n << endl; 
		for(int j = 0; j < n; j++){
			int x = 99996;
			out << x << " ";
		}
        out.close();
}

void sinhOutput(int numberTest) 
{
	for (int g = 1; g <= numberTest; g++) 
	{
		char fileIn[20];
		char fileOut[20];
		sprintf(fileIn,"%d.in", g);
		sprintf(fileOut, "%d.out", g);
		fstream in(fileIn, ios::in);
		fstream out(fileOut, ios::out);
		// bat dau sinh output
		memset(cnt, 0, sizeof cnt);
		in >> n;
  		for (int i = 0; i < n; i++) {
    		int foo;
    		in >> foo;
    		cnt[foo]++;
  		}
  		int ans = 1;
  		for (int i = 2; i < N; i++) {
    		int cur = 0;
    		for (int j = i; j < N; j += i) {
      			cur += cnt[j];
    		}
    		ans = max(ans, cur);
  		}
  		out << ans;
		in.close();
		out.close();
	}
}

int main() 
{
	int numberTest = 15;
	sinhInput(numberTest);
	sinhOutput(numberTest);
	cout << "Successfully!";
	return 0;
}
