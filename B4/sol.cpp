#include<iostream>
 using namespace std;
 main()
 {
   long a,b,v;
   cin>>a>>b>>v;
   float a1,b1,v1;
    a1=a,b1=b,v1=v;
   long sn=(v-b)/(a-b);
   if(sn<(v1-b1)/(a1-b1)) sn=sn+1;
   cout<<sn;
    // system("pause");
       }
