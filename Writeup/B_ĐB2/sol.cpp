#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define QT NN

using namespace std;

typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;

const ld pi=2*acos(0);
const int im = INT_MAX;
const int in = INT_MIN;
const int limit = 1e5+5;

int n, tmp, maxx, ucln;

void solve(){
    maxx = tmp;
    ucln = tmp;
    for(int i = 1; i < n; i++){
        cin>>tmp;
        maxx = max(maxx,tmp);
        ucln = __gcd(ucln,tmp);
    }
    int res = maxx/ucln-n;
    if(res>>1) cout<<"Lema"<<endl; else cout<<"Bi"<<endl;
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>tmp;
        solve();
    }
    return 0;
}
//Code by QT