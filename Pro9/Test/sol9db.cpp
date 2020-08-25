#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int lcm(int x, int y) {
    return x / __gcd(x, y) * y;
}

const int P = 2520;
LL pw[30], LCM[1 << 9], dp[30][1 << 9][P];

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

int main() {
    int TC; cin >> TC; Init();
    while (TC--) {
        LL L, R; cin >> L >> R;
        cout << Count(R + 1) - Count(L) << "\n"; // " - " << Count(L, R) << endl;
    }
    return 0;
}

