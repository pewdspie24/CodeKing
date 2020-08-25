#include<bits/stdc++.h>
using namespace std;
main()
{
		int a[1001];
		int n, max=0, c=0;
		cin>>n; 
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>max) max=a[i];
			if(a[i]%2==1) c=1;
		}
		if(c==0){
			int ch= (max-2)/2+1;
			ch=n-ch;
			if(ch%2) cout<<"Alice";
			else cout<<"Bob";
		}
		else {
			int d=max-n;
			if(d%2) cout<<"Alice";
			else cout<<"Bob";
		}
	return 0;
}