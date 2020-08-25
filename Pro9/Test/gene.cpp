#include<bits/stdc++.h>
#include <time.h> 
#define ld long double
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int P = 2520;
LL pw[30], LCM[1 << 9], dp[30][1 << 9][P];

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
		int t = 10;
		out << t << endl;
		while(t--){
			LL l = creat(1, 1e6);
			LL r = creat(l,1e6+1);
			out << l << " " << r << endl;
		}
		cout << "Complete test " << i << endl;
      out.close();
	}
	for (int i = 5; i < 11; i++) 
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		int t = 10;
		out << t << endl;
		while(t--){
			LL l = creat(1e6, 1e12-1);
			LL r = creat(l,1e12);
			out << l << " " << r << endl;
		}
		cout << "Complete test " << i << endl;
      out.close();
	}
	for (int i = 11; i < 16; i++)
	{
		char fileIn[20];
		sprintf(fileIn, "%d.in", i);
		fstream out(fileIn, ios::out);
		int t = 10;
		out << t << endl;
		while(t--){
			LL l = creat(1e12, 9*1e18-1);
			LL r = creat(l,9*1e18);
			out << l << " " << r << endl;
		}
		cout << "Complete test " << i << endl;
      out.close();
	}
}

//// Test dac biet
//	int i = 5;  // ma test dac biet
//	char fileIn[20];
//	sprintf(fileIn, "%d.in", i);
//	fstream out(fileIn, ios::out);
//	n = 686;
//	out << n << endl;
//	long long k = 10;
//	for(int j = 0; j < n; j++){
//		long long x;
//		long long sp[15] = {13, 20, 16, 8, 11, 4, 1, 2};
//		x = sp[j%8];
//		out << x << " ";
//	}
//	cout << "Complete special test" << endl;
//    out.close();
//}


int lcm(int x, int y) {
    return x / __gcd(x, y) * y;
}

void Init() {
    pw[0] = 1;
    for (int i = 1; i <= 20; ++i) pw[i] = pw[i - 1] * 10 % P;
    for (int x = 0; x < 1 << 9; ++x) {
        LCM[x] = 1;
        for (int i = 1; i <= 9; ++i) if (x >> (i - 1) & 1) LCM[x] = lcm(LCM[x], i);
    }
    memset(dp, -1, sizeof dp);
}

LL Compute(int i, int x, int f) {
    if (dp[i][x][f] != -1) return dp[i][x][f];
    if (i == 0) return (f % LCM[x] == 0);
    dp[i][x][f] = 0;
    for (int d = 0, g = f - pw[i - 1]; d < 10; ++d) {
        int y = (d == 0) ? x : (x | (1 << (d - 1)));
        g += pw[i - 1]; if (g >= P) g -= P;
        dp[i][x][f] += Compute(i - 1, y, g);
    }
    return dp[i][x][f];
}

LL Count(LL N) {
    int a[30], n = 0;
    while (N) {
        a[++n] = N % 10;
        N /= 10;
    }
    reverse(a + 1, a + 1 + n);

    LL ans = 0; int x = 0, f = 0;
    for (int i = 1; i <= n; ++i) {
        for (int d = 0; d < a[i]; ++d)
            ans += Compute(n - i, d == 0 ? x : (x | (1 << (d - 1))), (f + d * pw[n - i]) % P);
        if (a[i] != 0) x |= 1 << (a[i] - 1);
        f = (f + a[i] * pw[n - i]) % P;
    }
    return ans;
}

bool Check(int n) {
    int x = n;
    while (n) {
        int d = n % 10; n /= 10;
        if (d != 0 && x % d != 0) return false;
    }
    return true;
}

int Count(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; ++i) ans += Check(i);
    return ans;
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
		int TC; in >> TC; Init();
		clock_t tStart = clock();
    	while (TC--) {
      		LL L, R; in >> L >> R;
        	out << Count(R + 1) - Count(L) << "\n"; // " - " << Count(L, R) << endl;
    	}
		cout << "Test " << k << " complete" << endl;
		cout << "Time taken in test: " <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
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
