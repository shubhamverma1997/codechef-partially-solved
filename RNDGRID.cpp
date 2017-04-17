#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
  long long int t,l,n,counter,counter2,curi,curj,sindex,curi2,curj2,flag1=0,flag2=0;
  //char s[1002];
  scanf("%lld",&t);
  while (t)
  {
    long long int ans=0;
    scanf("%lld",&l);
    scanf("%lld",&n);
    char nn[1002][1002],s[5002];
    scanf("%s",s);
    for(register long long int i=0;i<n;i++)
    {
      scanf("%s",nn[i]);
    }
 
 
    for(register long long int i=0;i<n;i++)
    {
 
      for(register long long int j=i;j<n;j++)
      {
        curi=i;
        curj=j;
        curi2=j;
        curj2=i;
        flag1=0;flag2=0;
        if(nn[i][j]=='#')
          flag1=1;
        if(nn[j][i]=='#')
          flag2=1;
        if(i==j)
          flag2=1;
 
          sindex=0;
          counter=0;
          counter2=0;
          while(sindex!=l)
          {
            //cout<<"here"<<sindex<<" ";
            //cout<<sindex<<"<- "<<s[sindex]<<"|"<<curi<<"|"<<curj<<"|";
            if(flag1==1&&flag2==1)
              break;
            if(flag1==0)
            {
            if(s[sindex]=='U')
            {
              if( nn[curi-1][curj]=='.'  && curi!=0)
                {
                  //cout<<"u "<<nn[curi-1][curj]<<" ";
                  curi--;
                  counter++;
                }
              else
                {
                  //cout<<"breaku ";
                  flag1=1;
                }
            }
            if(s[sindex]=='D')
            {
              //cout<<"(ind) ";
              if( nn[curi+1][curj]=='.' && curi!=n-1 )
                {
                  //cout<<"d "<<nn[curi+1][curj]<<" ";
                  curi++;
                  counter++;
                }
              else
                {
                  //cout<<"breakd ";
                  flag1=1;
                }
            }
            if(s[sindex]=='L')
            {
              if( nn[curi][curj-1]=='.'  && curj!=0)
                {
                  //cout<<"l ";
                  curj--;
                  counter++;
                }
              else
                {
                  //cout<<"breakl ";
                  flag1=1;
                }
            }
            if(s[sindex]=='R')
            {
              if( nn[curi][curj+1]=='.'  && curj!=n-1)
                {
                  //cout<<"r ";
                  curj++;
                  counter++;
                }
              else
                {
                  //cout<<"breakr ";
                  flag1=1;
                }
            }
            }
 
 
            if(flag2==0)
            {
            if(s[sindex]=='U')
            {
              if( nn[curi2-1][curj2]=='.'  && curi2!=0)
                {
                  //cout<<"u "<<nn[curi-1][curj]<<" ";
                  curi2--;
                  counter2++;
                }
              else
                {
                  //cout<<"breaku ";
                  flag2=1;
                }
            }
            if(s[sindex]=='D')
            {
              //cout<<"(ind) ";
              if( nn[curi2+1][curj2]=='.' && curi2!=n-1 )
                {
                  //cout<<"d "<<nn[curi+1][curj]<<" ";
                  curi2++;
                  counter2++;
                }
              else
                {
                  //cout<<"breakd ";
                  flag2=1;
                }
            }
            if(s[sindex]=='L')
            {
              if( nn[curi2][curj2-1]=='.'  && curj2!=0)
                {
                  //cout<<"l ";
                  curj2--;
                  counter2++;
                }
              else
                {
                  //cout<<"breakl ";
                  flag2=1;
                }
            }
            if(s[sindex]=='R')
            {
              if( nn[curi2][curj2+1]=='.'  && curj2!=n-1)
                {
                  //cout<<"r ";
                  curj2++;
                  counter2++;
                }
              else
                {
                  //cout<<"breakr ";
                  flag2=1;
                }
            }
            }
 
 
            sindex++;
          }
          //cout<<i<<" "<<j<<" "<<counter<<endl;
          //cout<<j<<" "<<i<<" "<<counter2<<endl;
          ans=ans^counter^counter2;
      }
    }
    //cout<<endl;
    cout<<ans<<endl;
    t--;
  }
}
