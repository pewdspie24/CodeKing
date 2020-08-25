#include<bits/stdc++.h>
 
using namespace std;
 
const long long maxN = 5100;
long long dp[maxN], n;
long long a[maxN];
long long p[maxN];

bool can(long long i, long long j) {
	long long x = p[i];
	long long y = p[j] - (j - i - 1);
	if (y < 0) y = 0;
	return ((x == y - 1 && y > 0) || y == 0) && a[i] % a[j] == 0;
}
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
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
 
	cout << res << endl;
 
 
	return 0;
}
