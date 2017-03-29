#include<iostream>
using namespace std;
int main()
{
	int t,l,i,j,sum=0,sum1=0,temp=0;
	
	long a,d,r;
	cin>>t;
	while(t>0)
	{
		sum=0;temp=0,sum1=0;
	cin>>a;
	cin>>d;
	cin>>l;
	cin>>r;
	int x[r-l+1];
	for(i=l-1;i<=r-1;i++)
	{
		x[temp++]=a+(i*d);
	
	}
	for(i=0;i<r-l+1;i++)
	{
		
		while(x[i]>=10)
		{
		while(x[i]>0)
		{
			sum=sum+(x[i]%10);
			x[i]=x[i]/10;
			
		}
		x[i]=sum;
		sum=0;
		}
		sum1=sum1+x[i];
	}
	
	cout<<sum1<<endl;t--;
}
}
