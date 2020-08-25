#include<bits/stdc++.h>
#define ld long double
using namespace std;

typedef long long ll;
ll m = 1000000007;
ll n;
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
		n = creat(1, 1e2);
		out << n;
        out.close();
	}
	for (int i = 5; i < 11; i++) 
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = creat(1e2, 1e5);
		out << n;
        out.close();
	}
	for (int i = 11; i < 16; i++)
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		n = creat(1e5, 1e7);
		out << n;
        out.close();
	}
}

void sinhOutput(int numberTest) 
{
	for (int j = 1; j < 16; j++) 
	{
		long li, a, b;
		char fileIn[20];
		char fileOut[20];
		sprintf(fileIn,"%d.in", j);
		sprintf(fileOut, "%d.out", j);
		fstream in(fileIn, ios::in);
		fstream out(fileOut, ios::out);
		// bat dau sinh output
		ios_base::sync_with_stdio(0);
		cin.tie(0);
 		in >> n;
      	ll ans = 1, abc = 0;
      	for (ll i = 1; i <= n; i++) {
            ll d = abc * 3 % m;
      		int z = (abc * 2 + ans) % m;
      		ans = d;
      		abc = z;
      	}
      	out << ans%m;
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
