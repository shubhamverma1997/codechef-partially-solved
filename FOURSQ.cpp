#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;
long long int max_size,p;
vector<long long int > v(4);
int factor(long long int pro)
{
 
    long long int na,nb,nc,nd;
 for(register long long int i=0,na=p;i*i<=na;i++)
 {
     for(register long long int j=0,nb=na-i*i;j*j<=nb;j++)
     {
         for(register long long int k=0,nc=nb-j*j;k*k<=nc;k++)
         {
 
             for(register long long int l=0,nd=nc-k*k;l*l<=nd;l++)
             {
                 if(i*i+j*j+k*k+l*l==pro)
                    {
                        //cout<<"-"<<i<<j<<k<<l<<"-";
                        v.resize(4);
                        v[0]=i;
                        v[1]=j;
                        v[2]=k;
                        v[3]=l;
                        return 1;
                    }
             }
         }
     }
 }
 return 0;
}
void utility(long long int arr[],long long int *st,long long int low,long long int high,long long int pos)
{
    if(low==high)
        {
            st[pos]=arr[low]%p;
            return;
        }
    long long int mid=(low+high)/2;
    utility(arr,st,low,mid,2*pos+1);
    utility(arr,st,mid+1,high,2*pos+2);
    st[pos]=((st[2*pos+1]%p)*(st[2*pos+2])%p)%p;
}
long long int* ctree(long long int arr[],int n)
{
    long long int x=(long long int)ceil(log2(n));
    max_size=2*(long long int)pow(2,x)-1;
    long long int *st=new long long int[max_size];
    utility(arr,st,0,n-1,0);
    return st;
}
//************************************
 
//************************************
void update(long long int *st,long long  int low,long long int high,
            long long int pos,long long int value,long long int in)
{
        if(low==high) //&&low==in
        {
            st[pos]=value%p;
            return;
        }
    long long int mid=(low+high)/2;
    if(in<=mid)
    update(st,low,mid,2*pos+1,value,in);
    else
    update(st,mid+1,high,2*pos+2,value,in);
    st[pos]=((st[2*pos+1]%p)*(st[2*pos+2])%p)%p;
}
 
//************************************
long long int getp(long long int *st,long long  int ss,long long int se,
                   long long int qs,long long int qe,long long int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 1;
 
    // If a part of this segment overlaps with the given range
    int mid = (ss+se)/2;
    return ((getp(st, ss, mid, qs, qe, 2*si+1)%p) *
           (getp(st, mid+1, se, qs, qe, 2*si+2)%p))%p;
}
 
 
 
int main()
{
    int t;
    long long int n,q,num,x,y,pro;
    long long int arr[100001];
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%lld",&n);
        scanf("%lld",&q);
        scanf("%lld",&p);
 
 for(register long long int i=0;i<n;i++)
        {
            //cout<<"here";
            scanf("%lld",&arr[i]);
        }
    long long int *st=ctree(arr,n);
    /*for(int i=0;i<max_size;i++)
        cout<<st[i]<<" ";
     */
     for(register long long int i=0;i<q;i++)
     {
         scanf("%lld",&num);
         scanf("%lld",&x);
         scanf("%lld",&y);
 
         if(num==1)
         {
             arr[x-1]=y;
        update(st,0,n-1,0,y,x-1);
    /*for(int i=0;i<max_size;i++)
        cout<<st[i]<<" ";*/
         }
         else
         {
             pro=getp(st,0,n-1,x-1,y-1,0);
             //cout<<pro<<endl;
             if(factor(pro)==1)
                printf("%lld %lld %lld %lld\n",v[0],v[1],v[2],v[3]);
                else printf("-1\n");
         }
     }
        t--;
    }
 
}
