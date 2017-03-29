#include<iostream>
//#include<conio.h>
using namespace std;
int main()
{
    int n,j,k,l,a;
    long i,m;
    cin>>n;
    cin>>m;
    int set[n][1000];
    int query[4],index=0,numof=0;
    
        
    
    for(i=1;i<=m;i++)
    {
      cin>>query[0];
     
     if(query[0]==0)
     {
                     cin>>query[1]>>query[2]>>query[3];
                 for(j=query[1]-1;j<query[2];j++)
                    {
                       set[j][index]=query[3];                                           
                    }
                
                 
      index++;
        
     }
     else if(query[0]==1)
     {
         cin>>query[1];
                    for(j=1;j<=n;j++)
                    {
                    for(a=0;a<index;a++)
                    if(set[query[1]-1][a]==j)
                    {
                    numof++;
                   
                    break;
                    }
                    }
         cout<<numof<<endl;
     }
     numof=0;
    }
//getch();
}
