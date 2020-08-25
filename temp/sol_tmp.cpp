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

int absolute(int a, int b){
    if(a>=b) return a-b;
    else return b-a;
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        map <int,int> mymap;
        int n, tmp;
        cin>>n;
        vi mang;
        for(int i = 0; i < n; i++){
            cin>>tmp;
            mang.pb(tmp);
            mymap[tmp]++;
        }
        ll res = 0;
        while(true){
            int kt = 0;
            for(int i = 0; i < n-1; i++){
                for(int j = i; j < n; j++){
                    if(!mymap[absolute(mang[i],mang[j])]){
                        res++;
                        kt = 1;
                        mymap[absolute(mang[i],mang[j])]++;
                        break;
                    }
                    else continue;
                }
                if(kt == 1) break;
                if(kt == 0) continue;
            }
            if(kt == 0) break;
        }
        if(res%2) cout<<"Bi"<<endl;
        else cout<<"Lema"<<endl;
   }
    return 0;
}
//Code by QT