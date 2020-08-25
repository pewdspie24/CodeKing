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

ll S[1000000], Check[1000000];

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, tmp, L=0 ,R=0;
    vi A;
    vi B;
    cin>>n;
    ll res=0;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        A.pb(tmp);
    }
    for(int i = 0; i < n; i++){
        cin>>tmp;
        B.pb(tmp);
        if(i == 0) S[i] = B[i];
        else S[i] = S[i-1]+B[i];
    }
    for(int i = 0; i < n; i++){
        Check[i] = i;
        while(Check[i] - 1 >= 0 && A[i] >= A[Check[i]-1]) Check[i] = Check[Check[i]-1];
        ll sum = 0;
        if(Check[i] == 0) sum =  S[i];
        else sum = (S[i] - S[Check[i]-1]);
        if(res < sum){
            res = sum;
            L = Check[i];
            R = i;
        }
    }
    cout<<L<<" "<<R;
    return 0;
}
//Code by QT