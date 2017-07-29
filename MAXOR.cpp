#include<iostream>
#include<algorithm>
using namespace std;
long long int a[1000006];
int main()
{
	long long int t,n,count;
	scanf("%lld",&t);
	while(t)
	{
		count=0;
		scanf("%lld",&n);
		for(register long long int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(register long long int i=0;i<n-1;i++)
		{
			for(register long long int j=i+1;j<n;j++)
			{
				if((a[i]|a[j])<=max(a[i],a[j]))
					count++;
			}
		}
		printf("%lld\n",count);
		t--;
	}
}