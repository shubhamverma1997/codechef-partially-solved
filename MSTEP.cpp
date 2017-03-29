#include<iostream>
#include<math.h>
//#include<conio.h>
using namespace std;
int main(void)
{
    long long int t,n,i,j,sum=0,flag=1,fi,fj,m,k,l;
    cin>>t;
   
    for(l=0;l<t;l++)
    {
    cin>>n;
    m=n*n;
    long long int value[n][n];
    
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>value[i][j];
    
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
    if(value[i][j]==1)
    {
        fi=i;
        fj=j;
    }
    }
    while(flag<=m)
    {
                  
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    if(value[i][j]==flag)
                                    {sum=sum+sqrt(pow(fi-i,2))+sqrt(pow(fj-j,2));fi=i;fj=j;flag++;break;}
                    }
  
    }
    }
    cout<<sum<<endl;
    flag=1;sum=0;
    }  //  getch();
}
