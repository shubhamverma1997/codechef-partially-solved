//CHEFFA
#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

vector<int>::iterator it;
unordered_map< string , int > um;

int arr[100005];

int count,flag;
void answer(int start,int length)
{
	/*
	cout<<"start : "<<start<<" | ";
	for(register int i=0;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	*/

	int temp=start;
	flag=1;

	for(register int i=start;i<length-1;i++)
	{
		if(arr[i]>0 && arr[i+1]>0)
		{
			flag=0;	
			arr[i]--;
			arr[i+1]--;

			if(i+2==length)
			{

				
				arr[length]=1;
				string s="";
				for(int j=0;j<length+1;j++)
					s+=arr[j];
				if(um[s]==0)
				{
					um[s]=1;
					count++;
					answer(temp,length+1);
				}				
			}
			else
			{
				arr[i+2]++;
				string s="";
				for(int j=0;j<length;j++)
					s+=arr[j];
				if(um[s]==0)
				{
					count++;
					um[s]=1;
					answer(temp,length);
				}
				arr[i+2]--;
			}
			arr[i]++;
			arr[i+1]++;
		}
		else if(flag==1)
		{
			//flag=0;
			temp=i;
		}
	}	
}

int main()
{
	int t,n,len;
	scanf("%d",&t);
	while(t)
	{
		um.clear();
		count=1;
		scanf("%d",&n);
		for(register int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		answer(0,n);
		printf("%d\n",count);
		t--;
	}
}