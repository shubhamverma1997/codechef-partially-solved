#include<stdio.h>
using namespace std;
int main()
{
	int n,i,j,flag;
	scanf("%d",&n);
	int r[n];
	
	for(i=0;i<n;i++)
	scanf("%d",&r[i]);
	flag=1;
	
	for(j=1;j<n+1;j++)
	{
	flag=1;	
	for(i=0;i<n;i++)
	{
		if(j==r[i])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	printf("%d\n",j);
	}
	}
