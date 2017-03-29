#include<iostream>
 
using namespace std;
 
int main()
{
    int i,t,br,cr=0;
    int j,lim=0,n;
    cin>>t;
    while(t>0)
    {
    cin>>n;
    int balls[n],copy[n];    
    for(i=0;i<n;i++)
    {
    cin>>balls[i];
    if(lim<balls[i])
    lim=balls[i];
    }
    for(i=2;i<=lim;i++)
    {
                       cr=0;
           for(j=0;j<n;j++)
           {
                           if(balls[j]%i!=0)
                           {
                                            cr=cr+(i-(balls[j]%i));
                                            copy[j]=balls[j]+(i-(balls[j]%i));
                           }           
                           else
                           copy[j]=balls[j];
          // }
         //  for(j=0;j<n-1;j++)
          // {
                        if(j!=0&&copy[j-1]>copy[j])
                        {
                                             cr=cr+(copy[j-1]-copy[j]);
                                             copy[j]=copy[j-1];
                        }   
           }
           
           if(i==2)
           br=cr;
           if(cr<br)
           br=cr;
          
    }t--;
    cout<<br<<endl;
    }
}
