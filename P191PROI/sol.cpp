#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define oo 100005
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int n;
int ok[oo];
int kt[oo],foo[oo];
vector<int>a[oo],res;
map<pii,int>color;
void ReadInPut()
{
    n=read();
    F(i,1,n-1)
    {
        int x,y,mau;
        x=read();y=read();mau=read();
        a[x].pb(y);
        a[y].pb(x);
        color[mp(x,y)]=mau;
        color[mp(y,x)]=mau;
    }
}
int DFS(int u,int pu,int ca)
{
    ok[u]=1;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i];
        if(v==pu)continue;
        int mau=color[mp(u,v)];
        if(mau==color[mp(u,pu)]){ok[ca]=1;}
        DFS(v,u,ca);
    }
}
void Solve()
{
    for(int u=1;u<=n;u++)
    {
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            int mau=color[mp(u,v)];
            if(kt[mau]==u)
            {
                DFS(foo[mau],u,u);
                foo[mau]=v;
                DFS(v,u,u);
            }
            else{
                foo[mau]=v,kt[mau]=u;
            }
        }
    }
    F(i,1,n)
    {
        if(ok[i]==0)res.pb(i);
    }
    write(res.size());
    putchar('\n');
    for(int i=0;i<res.size();i++){
        write(res[i]);
        if(i<res.size()-1)putchar('\n');
    }
}
main()
{
  //  freopen("H.INP","r",stdin);
   // freopen(".OUT","w",stdout);
    ReadInPut();
    Solve();
}
