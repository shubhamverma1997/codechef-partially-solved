#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
 
void fastinput(long long int &number)
{
	//bool negative=false;
	register  long long int c=getchar_unlocked();
	number=0;
	for(;c>47 && c<58;c=getchar_unlocked())
		number=(number<<1)+(number<<3)+c-48;
}
 
bool prime[1000002];
long long int num[100000],counter=0,a[100001];
 
void sieve(long long int n)
{
	prime[1]=true;
	for(register long long int i=2;i*i<=n;i++)	
	{
		if(!prime[i])
		{
			for(register long long int j=i*2;j<=n;j+=i)
				prime[j]=true;
		}
	}
	for(register long long int i=2;i<1000002;i++)
	{
		if(!prime[i])
		{
			num[counter]=i;
			counter++;
		}		
	}
}
 
long long int  ceilsearch(long long int low
						 ,long long int high
						 ,long long int x)
{
	long long int mid;
	if(x<=num[low])
		return low;
	if(x>num[high])
		return -1;
	
	mid=(low+high)/2;
	if(num[mid]==x)
		return mid;
	else if(num[mid]<x)
	{
		if(mid+1<=high && x<=num[mid+1])
			return mid+1;
		else
			return ceilsearch(mid+1,high,x);
	}
	else
	{
		if(mid-1>=low && x>num[mid-1])
			return mid;
		else
			return ceilsearch(low,mid-1,x);
	}
}
 
long long int F(long long int l,long long int r,
				long long int x,long long int y
				,long long int n)
{
	long long  result=0,number;
	long long int index=ceilsearch(0,counter-1,x);
	
	if(index==-1)
		return result;
	//cout<<index<<" "<<num[index]<<endl;
	for(register long long int i=l-1;i<=r-1;i++)
	{
			
			//out<<num[i];
 
			if(!prime[a[i]])
			{
				if(a[i]>=x && a[i]<=y)
					result++;
				continue;
			}
 
			number=a[i];
			for(register long long int j=index;j<counter && num[j]<=y && num[j]<=(number);j++)
			{
				if(!prime[number])
				{
					if(number>=x && number<=y)
						result++;
					break;
				}
				
				if(number<j)
					break;
				while(number%num[j]==0)
				{
					result++;
					number=number/num[j];
				}
				//cout<<a[i]<<" "<<j<<" "<<num[j]<<" "<<result<<endl;
			}	
				
	}
		return result;
}
 
 
int main()
{
 
	num[0]=num[2];
	num[1]=num[2];
	long long int n,q,l,r,x,y;
	scanf("%lld",&n);
	sieve(1000000);
 
//78498
	
	//for(register long long int i=0;i<counter;i++)
		//cout<<num[i]<<" ";
	//cout<<endl<<counter<<endl;
	
	//fastinput(n);
 
	for(register long long int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		//fastinput(a[i]);
	}
	scanf("%lld",&q);
	//fastinput(q);
	for(register long long int i=0;i<q;i++)
	{
		scanf("%lld",&l);
		scanf("%lld",&r);
		scanf("%lld",&x);
		scanf("%lld",&y);
		
		/*
		fastinput(l);
		fastinput(r);
		fastinput(x);
		fastinput(y);
		*/
		//cout<<n<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
		printf("%lld\n",F(l,r,x,y,n));
	}
	
} 
