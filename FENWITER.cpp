#include<iostream>
#include<stdio.h>
#include<cstring>
#include<bitset>
 
#define LENGTH 100000
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    long long int counter=0;
    bitset<LENGTH> bitstore=0;
    bitset<LENGTH> sidekick=0;
    //bitset<LENGTH> auxb;
    //bitset<LENGTH> auxs;
 
    char l1[1001],l2[1001],l3[1001],newstring[LENGTH];
    long long int n;
    while(t>0)
    {
        counter=0;
        bitstore=0;
        //cout<<bitstore<<endl;
        scanf("%s",&l1);
        scanf("%s",&l2);
        scanf("%s",&l3);
        //cin>>l1>>l2>>l3;
        scanf("%lld",&n);
        strcpy(newstring,l1);
        while(n>0)
        {
                strcat(newstring,l2);
                n--;
        }
        strcat(newstring,l3);
 
    //cout<<newstring;
        long long int perm;
        perm=strlen(newstring);//////////////////////////////////////////////////////////
        //cout<<bitstore;
        bitstore=bitset<LENGTH>(string(newstring));
        //perm=newtemp;
        //adding one to the bits
        if(bitstore[0]==0)
            bitstore[0]=1;
        else
            {
                bitstore[0]=0;
                for(long long int i=1;;i++)
                {
                    if(bitstore[i]==0)
                    {
                        bitstore[i]=1;
                        break;
                    }
                    else
                        bitstore[i]=0;
                }
            }
        //cout<<endl<<bitstore<<endl;
 
        while(bitstore!=0)
        {
            sidekick=~bitstore;
 
          //  cout<<"now flipped  "<<endl<<sidekick<<endl;
            ///////////////////
            if(sidekick[0]==0)
            sidekick[0]=1;
        else
            {
                sidekick[0]=0;
                for(register long long int i=1;i<=perm;++i)
                {
                    if(sidekick[i]==0)
                    {
                        sidekick[i]=1;
                        break;
                    }
                    else
                        sidekick[i]=0;
                }
            }
            //cout<<"Here out"<<endl<<sidekick<<endl;
                sidekick=bitstore&sidekick;
              //  cout<<"bitstore---->"<<endl<<bitstore<<endl;
                //cout<<"AND operation"<<endl<<sidekick<<endl;
/*
                for(register long long int i=0;i<=perm;++i)
                {
                    if(sidekick[i]==bitstore[i])
                        {
                            bitstore[i]=0;
                            continue;
                        }
                    if(sidekick[i]=0&&bitstore[i]==1)
                    {
                        bitstore[i]=1;
                        continue;
                    }
                    if(sidekick[i]==1&&bitstore[i]==0)
                    {
                        long long int j=0;
                        for(j=i;j<=perm;j++)
                        {
                            if(bitstore[j]==1)
                            {
                                bitstore[j]=0;
                                break;
                            }
                            else
                            {
                                bitstore[j]=1;
                            }
                        }
 
                    }
                }*/
            //cout<<"-->"<<bitstore<<"<--"<<endl;
            //bitstore[LENGTH-1]=0;
            //auxb=bitstore;
            //auxs=sidekick;
            while(sidekick!=0)
            {
                //cout<<"here";
                bitstore=bitstore^sidekick;
                sidekick=((bitstore)&sidekick)<<1;
            }
            //cout<<"out";
            counter++;
 
        }
/*        while(num>0)
        {
            num=num-(num&(-num));
            counter++;
        }
        */
        printf("%lld\n",counter);//cout<<counter<<endl;
        t--;
    }
}
