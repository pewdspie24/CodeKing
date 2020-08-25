#include<bits/stdc++.h>
#define ld long double
using namespace std;

const long long maxN = 5100;
long long dp[maxN], n;
long long a[maxN];
long long p[maxN];

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
//		n = creat(2, 50);
//		out << n << endl;
//		for(int j = 0; j < n; j++){
//			long long x = creat(1,1e5);
//			out << x << " ";
//		}
//		cout << "Complete test " << i << endl;
//      out.close();
//	}
//	for (int i = 5; i < 11; i++) 
//	{
//		char fileIn[20];
//		sprintf(fileIn, "%d.in", i);
//		fstream out(fileIn, ios::out);
//		n = creat(50, 500);
//		out << n << endl;
//		for(int j = 0; j < n; j++){
//			long long x = creat(1e5,1e10);
//			out << x << " ";
//		}
//		cout << "Complete test " << i << endl;
//      out.close();
//	}
//	for (int i = 11; i < 16; i++)
//	{
//		char fileIn[20];
//		sprintf(fileIn, "%d.in", i);
//		fstream out(fileIn, ios::out);
//		n = 5000;
//		out << n << endl;
//		for(int j = 0; j < n; j++){
//			long long x = creat(1e10,1e15);
//			out << x << " ";
//		}
//		cout << "Complete test " << i << endl;
//      out.close();
//	}

// Test dac biet
	int i = 5;  // ma test dac biet
	char fileIn[20];
	sprintf(fileIn, "%d.in", i);
	fstream out(fileIn, ios::out);
	n = 686;
	out << n << endl;
	long long k = 10;
	for(int j = 0; j < n; j++){
		long long x;
		long long sp[15] = {13, 20, 16, 8, 11, 4, 1, 2};
		x = sp[j%8];
		out << x << " ";
	}
	cout << "Complete special test" << endl;
    out.close();
}


bool can(long long i, long long j) {
	long long x = p[i];
	long long y = p[j] - (j - i - 1);
	if (y < 0) y = 0;
	return ((x == y - 1 && y > 0) || y == 0) && a[i] % a[j] == 0;
}

void sinhOutput(int numberTest) 
{
	cout <<  "----------bat dau sinh output----------------" << endl;
	for (int k = 1; k <= numberTest; k++) 
	{
		char fileIn[20];
		char fileOut[20];
		sprintf(fileIn,"%d.in", k);
		sprintf(fileOut, "%d.out", k);
		fstream in(fileIn, ios::in);
		fstream out(fileOut, ios::out);
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(p,0, sizeof p);
		memset(dp,0,sizeof dp);
 		in >> n;
		for (int i = 1; i <= n; ++i) {
			in >> a[i];
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				++p[i];
			}
		}
		for (int i = 1; i <= n; ++i) {
			dp[i] = i - 1;
			for (int j = 1; j < i; ++j) {
				if (can(j, i)) {
					dp[i] = min(dp[i], dp[j] + i - j - 1);
				}
			}
		}
		long long res = n - 1;
		for (int i = 1; i <= n; ++i) {
			res = min(res, dp[i] + n - i);
		}
		out << res << endl;
		cout << "Test " << k << " complete - " << "res " << res << endl;
		in.close();
		out.close();
	}
}

int main() 
{
	int numberTest = 15;
	//sinhInput(numberTest);
	sinhOutput(numberTest);
	cout << "Successfully!";
	return 0;
}
