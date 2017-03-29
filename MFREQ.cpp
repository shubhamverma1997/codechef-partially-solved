#include<iostream>
#include<stdio.h>
#include<utility>
 
using namespace std;
 
long long int a[100000];
 
int main()
{
	long long int n,m,l,r,k,temp,counter,flag;
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(register long long int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(register long long int i=0;i<m;i++)
	{
		counter=1;
		scanf("%lld",&l);
		scanf("%lld",&r);
		scanf("%lld",&k);
		temp=a[l-1];
		
		flag=0;
		for(register long long int i=l;i<r;i++)
		{
 
			if(a[i]==temp)
				{
					counter++;
					//cout<<"here1 "<<counter;
					//continue;
					
				}
			else
			{
				temp=a[i];
				counter=1;
				//cout<<"here2 ";
			}
			
			if(counter>=k)
			{
				printf("%lld\n",temp);
				flag=1;
				break;
			}
		}
 
		if(counter>=k&&flag==0)
		{
			printf("%lld\n",temp);
		}
		else if(counter<k)
		printf("-1\n");
	}
 
}
