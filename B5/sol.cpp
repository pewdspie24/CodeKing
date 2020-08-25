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
const ll M = 1e9+7;

ll n,x,tong,soNguoi;

void solve(){
    for(int i = 0; i < n; i++){
        tong += soNguoi;
        // tong%=M;
        soNguoi=tong*x;
        // soNguoi%=M;
        // cout<<tong<<endl;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        cin>>x>>n;
        tong = 0;
        soNguoi=1;
        solve();
        cout<<tong<<endl;
   }
    return 0;
}
//Code by QT