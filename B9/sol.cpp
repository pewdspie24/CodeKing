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

ll powQ(ll a, ll b){
    if(b <= 0) return 1;
    ll res = powQ(a,b/2);
    res = res*res%M;
    if(b%2!=0) res = res*a%M;
    return res;  
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n,m,ans=0;
    ll f[limit];
    f[0] = 1;
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        for(int j = i; j > 0; j--){
            f[j] = (f[j]*j+f[j-1]*(n-j+1))%M;
        }
        f[0] = 0;
    }
    for(int i = 1; i <= m; i++) cout<<f[i]<<endl;
    for(int i = 1; i <= m; i++) ans = (ans+f[i]*powQ(2,n-i))%M;
    cout<<ans;
    return 0;
}
//Code by QT