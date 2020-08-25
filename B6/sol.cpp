#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //freopen("10.in","r",stdin);
    //freopen("10.out","w",stdout);
    cin>>n>>m;
	while(m%n!=0){
		cout<<-1;
		return 0;
	}
	m/=n;
	int dem=0;
	while(m>1){
		if(m%2==0) m/=2,dem++;
		else if(m%3==0) m/=3,dem++;
		else break;
	}
	if(m>1) cout<<-1;
	else cout<<dem;
    return 0;
}