#include<bits/stdc++.h>
#define ld long double
using namespace std;

long long n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long creat(long long a ,long long b)						
{											
	return (long long)rng() % (b - a + 1) + a;					// Create random number in [a, b]
}

void sinhInput(int numberTest) 
{
	for (int i = 1; i < 5; i++) 
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = 40000;
		out << n << endl; 
		for(int j = 0; j < n; j++){
			long long x = creat(1, 1e4);
			out << x << " ";
		}
        out.close();
	}
	for (int i = 5; i < 11; i++) 
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = 40000; 
		out << n << endl; 
		for(int j = 0; j < n; j++){
			long long x = creat(1e4, 1e8);
			out << x << " ";
		}
        out.close();
	}
	for (int i = 11; i < 16; i++)
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = 40000; 
		out << n << endl;
		for(int j = 0; j < n; j++){
			long long x = creat(1e8, 1e12);
			out << x << " ";
		}
        out.close();
	}
}

void sinhOutput(int numberTest) 
{
	for (int j = 1; j < 16; j++) 
	{
		char fileIn[20];
		char fileOut[20];
		sprintf(fileIn,"%d.in", j);
		sprintf(fileOut, "%d.out", j);
		fstream in(fileIn, ios::in);
		fstream out(fileOut, ios::out);
		// bat dau sinh output
		in >> n;
		long long g = 0;
		for (int i = 0; i < n; ++i) {
			long long x;
			in >> x;
			g = __gcd(g, x);
		}
		int ans = 0;
		for (int i = 1; i * 1ll * i <= g; ++i) {
			if (g % i == 0) {
				++ans;
				if (i != g / i) {
					++ans;
				}
			}
		}		
		out << ans << endl;
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
