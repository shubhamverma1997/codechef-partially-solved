#include<iostream>
//#include<conio.h>
using namespace std;
int main()
{
    int n,i=0,j=0,t,count=0,k;
    cin>>t;
    while(t>0)
    {
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
    }
    k=a[0];
    for(i=0;i<n,j<n;)
    {
       
    
    {
       if(k<=a[j])
       {
                     count++;
                     k=a[j];
                     if(j!=n-1) j++;
                     else {
                          i++;j=i;k=a[i];
                          }
       }
       else 
       {
            i++;j=i;k=a[i];
       }
    }
    }
    cout<<count<<endl;
    
    t--;
    count=0;j=0;
    }
    //getch();
}
