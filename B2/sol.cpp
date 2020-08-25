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

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        string ans="";
        int i=0;
        while(i < s.length()){
            if(s[i] == '9'){
                int tmp = int(s[i]-'0')*10+int(s[i+1]-'0')-97;
                // cout<<tmp<<endl;
                char temp = tmp+'a';
                cout<<temp;
                // ans= ans + temp;
                i+=2;
            }
            else{
                int tmp = int(s[i]-'0')*100+int(s[i+1]-'0')*10+int(s[i+2]-'0')-97;
                // cout<<tmp<<endl;
                char temp = tmp+'a';
                cout<<temp;
                // ans= ans + temp;
                i+=3;
            }
        }
        cout<<endl;
        // cout<<ans<<endl;
    }
    return 0;
}
//Code by QT