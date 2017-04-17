//partially accepted
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
  long long int t,n,q,temp,index,l,r,k;
  long long int arr[100001],sum[100001];
  scanf("%lld",&t);
  while (t)
  {
    scanf("%lld\n",&n);
    scanf("%lld\n",&q);
    scanf("%lld\n",&arr[0]);
    sum[n-1]=1;
    for(register long long int i=1;i<n;i++)
    {
      scanf("%lld",&arr[i]);
    }
 
    for(register long long int i=n-2;i>=0;i--)
    {
      if(arr[i]==arr[i+1])
      {
        sum[i]=sum[i+1]+1;
      }
      else
      {
        sum[i]=1;
      }
    }
    /*
    for(int i=0;i<n;i++)
      cout<<sum[i]<<" ";
    cout<<endl;
    */
    long long int ans=0,pivot;
    for(register long long int j=0;j<q;j++)
    {
      ans=0;
      scanf("%lld",&l);
      scanf("%lld",&r);
      scanf("%lld",&k);
      register long long int m;
      
      for(m=l-1;m<r;)
      {
        //cout<<m<<" "<<arr[m]<<" "<<sum[m]+m-1<<" "<<r<<endl;
        if(m+sum[m]-1<r)
        {
          //cout<<"here";
          if(sum[m]>=k)
            {
              ans++;
              //cout<<"in1 ";
            }
          m+=sum[m];
        }
        else
        {
          //cout<<"there";
          if(sum[m]-sum[r-1]+1>=k)
          {
            //cout<<"in2 ";
            ans++;
          }
          break;
        }
      }
       cout<<ans<<endl;
    }
 
    t--;
  }
}
