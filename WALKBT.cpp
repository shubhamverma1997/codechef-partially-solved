#include<iostream>
#include<unordered_map>
#include<bitset>
#include<cstring>
#include<stdio.h>
#include<unordered_map>
#define size 2005//change to above 2000
#define decsize 100
int count[decsize],digits;
using namespace std;

bitset<size> add(bitset<size> a, bitset<size> b)
{
	bitset<size> ans;
    long long int carry = 0 , i = 0; 
    while(i<size)
    {
	    ans[i]=carry^a[i]^b[i];
	    carry=(carry&a[i])|(a[i]&b[i])|(carry&b[i]);
	    i++;
	}
	return ans;
}

void adddec()
{
	int i=0,carry=1;
	while(carry!=0 || i<digits)
	{
		count[i]=count[i]+carry;
		carry=count[i]/10;
		count[i]=count[i]%10;
		i++;
	}
	digits=i;
}


int main()
{
	
	long long int t,n,q,c;
	char ch;
	scanf("%lld",&t);
	while(t)
	{
		unordered_map< bitset< size > , int > um;
		bitset<size> x,one;

		digits=0;
		scanf("%lld",&n);
		scanf("%lld",&q);
		//cout<<n<<" "<<q<<"\n";
		memset(count,0,decsize*sizeof(int));
		if(q>0)
		{
			adddec();
		}
		for(register long long int i=0;i<q;i++)
		{
			cin>>ch;
			//cout<<ch<<" | ";
			if(ch=='!')
			{
				scanf("%lld",&c);
				//cout<<c<<endl;
				one[c]=1;
				x=add(x,one);
				//for(register int i=n;i<size;i++)
				//	x[i]=0;
				x[n]=0;
				//cout<<x<<endl;
				one[c]=0;
				bitset<size> temp;
				temp[0]=1;//differentiator
				for(register int i=n-1;i>=0;i--)
				{
					temp<<=1;
					temp[0]=x[i];
					if(um[temp]==0)
					{
						adddec();
						um[temp]=1;
					}
					else
					{
						//cout<<"here"<<temp<<endl;
						//continue;
					}
					
				}
			}
			else
			{
				for(register int i=digits-1;i>=0;i--)
				{
					printf("%d",count[i]);
				}
				cout<<"\n";
			}
		}
		t--;
	}
}
