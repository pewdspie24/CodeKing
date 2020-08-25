#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t;
int n, m;
int d[N], h[N];

int main() {
	cin >> t;
	for(int tc = 0; tc < t; ++tc){
		cin >> n >> m;
		int maxDH = -2e9;
		for(int i = 0; i < n; ++i){
			cin >> d[i] >> h[i];
			maxDH = max(maxDH, d[i] - h[i]);
		}

		int res = 1;	
		int maxD = *max_element(d, d + n);
		m -= maxD;
		if(m > 0){
			if(maxDH <= 0) res = -1;
			else res += (m + maxDH - 1) / maxDH; 	
		}	
		if(res == -1) cout << "-1" << endl;
		else cout << res << endl;
	}
	
	return 0;
}
