#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
long int a[1000000];
long int bs(vector<int> arr,long int l,long int r,long int key)
{
    long int mid;
    while(r-l>1)
    {
        mid=l+(r-l)/2;
        if(key<=arr[mid])
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
long int lis(long int n,long int l,long int r)
{
    if(n==0)
        return 0;
    long int length=1;
    vector<int> lister(n,0);
    lister[0]=a[l-1];
    for(long int i=l;i<r;i++)
    {
        if(a[i]<lister[0])
        {
            lister[0]=a[i];
            continue;
        }
        else if(a[i]>lister[length-1])
        {
            lister[length++]=a[i];
        }
        else
        {
            lister[bs(lister,-1,length-1,a[i])]=a[i];
        }
    }
    return length;
}
int main()
{
    long int t;
    long int n,m,l,r;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        cin>>m;
        for(long int i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
        for(long int i=0;i<m;i++)
        {
            scanf("%ld",&l);
            scanf("%ld",&r);
            cout<<lis(n,l,r)<<endl;
        }
        t--;
    }
}
