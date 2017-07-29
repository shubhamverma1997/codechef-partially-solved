//LOCJUL17
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int t,n,m,a;
	double ans;
	scanf("%lld",&t);
	while(t)
	{
		scanf("%lld",&n);
		scanf("%lld",&m);
		ans=sqrt(2*m);
		if(ans>n)
		{
			printf("-1\n");
			t--;
			continue;
		}
		a=(long long int)(ans);
		if( (long long int)(ans) == ans)
			{	
				printf("%lld\n",a);
			}
		else if( (long long int)(ans) == (long long int)(ans+0.5))
			{
				printf("%lld\n",a);
			}
		else if( (long long int)(ans) == (long long int)(ans-0.5))
		{
				printf("%lld\n",a+1);
		}

		//cout<<ans<<endl;

		//printf("%lld\n",ans);
		t--;
	}
}