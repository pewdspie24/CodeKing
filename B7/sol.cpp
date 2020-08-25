#include <bits/stdc++.h>
#include <string.h>
#include <string>
 
using namespace std;
int main ()
{
	int t;
	cin>>t;	
	for(int hoai = 0; hoai < t; hoai++)
	{
		long long n[1000]={0},x[1000]={0},Clean[1000]={0};
		long long Num=0,Num_Head=0,max=0,min=0;
		cin>>Num>>Num_Head;
		for(int i = 0; i < Num; i++)
		{
			cin>>n[i]>>x[i];
			Clean[i] = n[i]-x[i];
			if(max < n[i])
			{
				max = n[i];
				min = x[i];
			}
		}
		sort(Clean,Clean+Num, greater<int>());
		if(max >= Num_Head)
		cout<<"1"<<endl;
		else if (Clean[0] <= 0)
		cout<<"MISSION FAILED!"<<endl;
		else
		{
			Num_Head -= max;
			if (Num_Head % Clean[0] != 0)
			cout<<Num_Head/Clean[0]+2<<endl;
			else
			cout<<Num_Head/Clean[0]+1<<endl;
		}
	}	
	return 0;
}
// code by QT