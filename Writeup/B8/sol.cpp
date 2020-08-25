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

ll n,k;
ll dp[5001][5001]={0};

ll powQ(ll a, ll b){
    if(b <= 0) return 1;
    ll res = powQ(a,b/2);
    res = res*res%M;
    if(b>>1) res = res*a%M;
    return res;  
}

ll solve(ll a, ll b){
    if(b > n) return 0;
    if(dp[a][b] > 0) return dp[a][b];
    ll c = n-b;
    if(a == 0){
        dp[a][b] = powQ(2,c);
        return dp[a][b];
    }
    dp[a][b] = (b*solve(a-1,b) + c*solve(a-1,b+1))%M;
    return dp[a][b];
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    cout<<powQ(10,3);
    return 0;
}
//Code by QT