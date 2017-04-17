#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  long long int t,l,r,a[10],counter,flag,sum;
  scanf("%lld",&t);
  while (t)
  {
    counter=0;
    sum=0;
    scanf("%lld",&l);
    scanf("%lld",&r);
    for(register int i=0;i<10;i++)
    {
      scanf("%lld",&a[i]);
      sum+=a[i];
    }
    if(sum==0)
    {
      for(register long long int i=1023456789;i<=r;i++)
    {
      //cout<<"here";
      flag=0;
      long long int num=i,dig[10]={0,0,0,0,0,0,0,0,0,0};
      while(num!=0)
      {
        dig[num%10]++;
        num=num/10;
      }
      for(register long long int j=0;j<10;j++)
      {
        if(a[j]==dig[j])
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        counter++;
      }
    }
    printf("%lld\n",counter);
    t--;     
    continue;
    }
 
 
 
    for(register long long int i=l;i<=r;i++)
    {
      //cout<<"here";
      flag=0;
      long long int num=i,dig[10]={0,0,0,0,0,0,0,0,0,0};
      while(num!=0)
      {
        dig[num%10]++;
        num=num/10;
      }
      for(register long long int j=0;j<10;j++)
      {
        if(a[j]==dig[j])
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        counter++;
      }
    }
    printf("%lld\n",counter);
    t--;
  }
 
}
