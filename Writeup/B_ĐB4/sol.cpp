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

ll gt[limit],inv[limit],f[1005][2];
int n,m;

ll powQ(ll a, ll b){
    if(b <= 0) return 1;
    ll res = powQ(a,b/2);
    res = res*res%M;
    if(b%2!=0) res = res*a%M;
    return res;  
}

void input(){
    gt[0] = 1;
    cin>>n>>m;
    for(int i = 1; i <= n; i++) gt[i]=(gt[i-1]*i)%M;
    for(int i = 0; i <= n; i++) inv[i]=powQ(gt[i],M-2);
}

ll solve(){
    for(int i = 1; i <= n; i++) f[i][0] = gt[i-1];
    for(int j = 2; j <= m; j++){
        ll tmp = f[j-1][0]*inv[j-1]%M;
        for(int i = j; i <= n; i++){
            f[i][1] = gt[i-1]*tmp%M;
            tmp = (tmp+f[i][0]*inv[i]%M)%M;
        }
        for(int i = j; i <= n; i++) f[i][0] = f[i][1];
    }
    return f[n][0];
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    cout<<solve();
    return 0;
}
//Code by QT