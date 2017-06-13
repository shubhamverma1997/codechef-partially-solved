#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int t,n,q,arr[100001],a,b,c,d,ta[100001],tb[100001];
	scanf("%lld",&t);
	while(t)
	{
		scanf("%lld",&n);
		scanf("%lld",&q);
		for(register long long int i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		for(register long long int i=0;i<q;i++)
		{
			scanf("%lld",&a);
			scanf("%lld",&b);
			scanf("%lld",&c);
			scanf("%lld",&d);
			for(register long long int i=a-1;i<=b-1;i++)
			{
				ta[i-a+1]=arr[i];
			}
			for(register long long int i=c-1;i<=d-1;i++)
			{
				tb[i-c+1]=arr[i];
			}
			sort(ta,ta+b-a+1);
			sort(tb,tb+d-c+1);

			/*
			for(register long long int i=0;i<b-a+1;i++)
			{
				cout<<ta[i]<<" "<<tb[i]<<endl;
			}*/

			long long int flag=0;
			for(register long long int i=0;i<b-a+1;i++)
			{
				if(flag==2)
					break;
				if(ta[i]!=tb[i])
				{
					flag++;
				}
			}
			if(flag<=1)
				printf("YES\n");
			else
				printf("NO\n");

		}
		t--;
	}
}
