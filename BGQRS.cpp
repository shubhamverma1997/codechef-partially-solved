#include<iostream>
#include<stdio.h>
using namespace std;
 
int main()
{
    long int array[100000];
    long long int t,a,b,c,d;
    long long int n,m;
    cin>>t;
    while(t>0)
    {
        long long int type3=0;
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(register long long int i=0;i<n;i++)
            scanf("%lld",&array[i]);
            /*for(long int i=0;i<n;i++)
    /*cout<<array[i]<<" ";
cout<<endl;
cout<<type3<<endl;*/
        for(register long long int j=0;j<m;j++)
        {
            long int trail=0,five=0,two=0;
            scanf("%lld",&a);
            scanf("%lld",&b);
            scanf("%lld",&c);
            if((a==1||a==2))
            scanf("%lld",&d);
            if(a==1)
            {
                for(register long long int i=b-1;i<c;i++)
                {
                    array[i]=array[i]*d;
                }
                /*for(long int i=0;i<n;i++)
    /*cout<<array[i]<<" ";
cout<<endl;
cout<<type3<<endl;*/
                continue;
            }
            if(a==2)
            {
                long long int counter=1;
                for(register long long int i=b-1;i<c;i++)
                {
                    array[i]=d*counter;
                    counter++;
                }
              /*  for(long int i=0;i<n;i++)
    /*cout<<array[i]<<" ";
cout<<endl;
cout<<type3<<endl;*/
                continue;
            }
            if(a==3)
            {
 
                for(register long long int i=b-1;i<c;i++)
                {
                    long long int temp=array[i];
                    while(1)
                    {
                        if(temp%2==0&&temp!=0)
                            {
                                two++;
                                temp=temp/2;
                            }
                        else
                            break;
 
                    }
                    while(1)
                    {
                        if(temp%5==0&&temp!=0)
                            {
                                five++;
                                temp=temp/5;
                            }
                        else
                            break;
 
                    }
 
 
                }
                if(five>=two)
                        type3=type3+two;
                    else
                        type3=type3+five;
 
            }
            /*for(long int i=0;i<n;i++)
    cout<<array[i]<<" ";
cout<<endl;
cout<<type3<<endl;*/
        }
        cout<<type3<<endl;
        t--;
    }
}
