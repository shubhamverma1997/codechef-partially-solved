//HILLJUMP
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
	ll n,q,a[100005],l,r,x,f,flag,in,temp,cindex;
	scanf("%lld",&n);
	scanf("%lld",&q);
	for(register long long int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(register long long int i=0;i<q;i++)
	{
		scanf("%lld",&f);
		if(f==1)
		{
			scanf("%lld",&l);
			scanf("%lld",&r);
			cindex=l;
			while(r)
			{
				temp=cindex;
				while(temp-cindex<=100 && temp<=n)
				{
					if(a[cindex]<a[temp] && temp<=n)
					{
						cindex=temp;
						r--;
						break;
					}
					temp++;
				}
				if(temp-cindex>100 || temp>n)
				{
					break;
				}
			
			}
			printf("%lld\n",cindex);
			
		}
		else
		{
			scanf("%lld",&l);
			scanf("%lld",&r);
			scanf("%lld",&x);
			for(register ll j=l;j<=r;j++)
			{
				a[j]+=x;	
			}
		}
	}
}