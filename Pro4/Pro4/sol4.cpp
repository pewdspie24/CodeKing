#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1234567;
 
int cnt[N];
 
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
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
  cout << ans;
  return 0;
}
