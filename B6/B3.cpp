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

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        ll dem = 0;
        while(n!=1){
            if(n%3==0){
                n/=3;
                dem++;
            }
            else if(n%3==1){
                n--;
                dem++;
                n/=3;
                dem++;
            }
            else{
                if(n%2==0){
                    n/=2;
                    dem++;
                }
                else{
                    dem+=2;
                    n-=2;
                    n/=3;
                    dem++;
                }
            }
        }
        cout<<dem<<endl;
   }
    return 0;
}
//Code by QT