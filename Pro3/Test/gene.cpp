#include<bits/stdc++.h>
#define ld long double
using namespace std;

const int N = 105;
int d[N], h[N];
long long t, a, b;
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
		t = 100;
		out << t << endl; 
		a = creat(1, 100); b = creat(1, 1e4);
		out << a << " " << b << endl;
		for(int j = 0; j < a; j++){
			long long x = creat(1, 1e3);
			long long y = creat(1, 1e3);
			out << x << " " << y << endl;
		}
        out.close();
	}
	for (int i = 5; i < 11; i++) 
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		t = 100;
		out << t << endl; 
		a = creat(1, 100); b = creat(1e4, 1e8);
		out << a << " " << b << endl;
		for(int j = 0; j < a; j++){
			long long x = creat(1e3, 1e6);
			long long y = creat(1e3, 1e6);
			out << x << " " << y << endl;
		}
        out.close();
	}
	for (int i = 11; i < 16; i++)
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		t = 100;
		out << t << endl; 
		a = creat(1, 100); b = creat(1e8, 1e12);
		out << a << " " << b << endl;
		for(int j = 0; j < a; j++){
			long long x = creat(1e6, 1e9);
			long long y = creat(1e6, 1e9);
			out << x << " " << y << endl;
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
		in >> t;
		for(int tc = 0; tc < t; ++tc){
			in >> a >> b;
			int maxDH = -2e9;
			for(int i = 0; i < a; ++i){
				in >> d[i] >> h[i];
				maxDH = max(maxDH, d[i] - h[i]);
			}
			int res = 1;	
			int maxD = *max_element(d, d + a);
			b -= maxD;
			if(b > 0){
				if(maxDH <= 0) res = -1;
				else res += (b + maxDH - 1) / maxDH; 	
			}	
			if(res == -1) out << "Social Quarantine" << endl;
			else out << res << endl;
		}
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
