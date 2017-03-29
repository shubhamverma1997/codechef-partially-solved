#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<cstring>
#include<utility>
using namespace std;
 
long long int n,e,a,b;
vector<long long int> v[100001];
bool visited[100001];
long long int sizer[100001];
vector<pair<long long int,long long int > > p,ans;
 
 
long long int temp;
 
void traversal(long long int u)
{
 
    for(vector<long long int>::iterator it =v[u].begin();it!=v[u].end();it++)
    {
            if(*it==-1)
                continue;
            temp=*it;
            sizer[(*it)]--;
            *it=-1;
 
            for(vector<long long int >::iterator jt=v[temp].begin();jt!=v[temp].end();jt++)
            {
                if(*jt==u)
                {
                    //v[temp].erase(jt);
                    sizer[(*jt)]--;
                    *jt=-1;
                    break;
                }
            }
            //cout<<endl<<u<<" "<<temp;
            ans.push_back(make_pair(u,temp));
 
            traversal(temp);
    }
}
void check(long long int vertex)
{
    visited[vertex]=true;
    vector<long long int>::iterator it;
 
    for(it=v[vertex].begin();it!=v[vertex].end();it++)
    {
        //cout<<"chechk"<<*it<<visited[*it]<<" ";
        if(!visited[*it])
            check(*it);
    }
}
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&e);
 
    for(register long long int i=0;i<e;i++)
    {
        scanf("%lld",&a);
        scanf("%lld",&b);
        v[a].push_back(b);
        v[b].push_back(a);
        p.push_back(make_pair(a,b));
        sizer[a]++;
        sizer[b++];
    }
 
    /*cout<<endl; //for displaying content
    for(int i=1;i<=n;i++)
    {
        for(vector<long long int>::iterator it=v[i].begin();it!=v[i].end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }*/
 
    //cout<<"int";
    int flag=1;
    /*for(register long long int i=1;i<=n;i++)
    {
        if(v[i].size()&1)
        {
            flag=0;
            printf("NO\n");
            break;
        }
    }*/
    if(flag)
    {
        //cout<<"inside";
        int conflag=1;
        //fill(visited,visited+100001,false);
        /*for(register int i=0;i<1000;i++)
            cout<<visited[i];
        */
                check(1);
 
        for(register long long int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                printf("NO\n");
                conflag=0;
                break;
            }
        }
        //now starts the algorithm
        if(conflag)
        {
            for(long long int i=1;i<=n;i++)
                {
                    if(v[i].size()&1)
                    {
                        conflag=0;
                        printf("NO\n");
                        break;
                    }
                    //if(sizer[i]!=0)
 
                }
                if(conflag)
            {
                traversal(1);
                printf("YES\n");
            /*for(vector < pair < long long int , long long int > >::iterator it=ans.begin();it!=ans.end();it++)
            {
                //cout<<"here";
                cout<<(*it).first<<" "<<(*it).second<<endl;
            }*/
 
            pair <long long int ,long long int> temp,invtemp;
            //int pflag=1;
            for(vector <pair <long long int ,long long int> >::iterator it=p.begin();it!=p.end();it++)
            {
                temp=(*it);
                invtemp.first=temp.second;
                invtemp.second=temp.first;
                for(vector <pair <long long int ,long long int> >::iterator jt=ans.begin();jt!=ans.end();jt++)
                {
                    if(temp==(*jt))
                    {
                        //ans.erase(jt);
                        printf("%lld %lld\n",temp.first,temp.second);
                        break;
                    }
                    else if(invtemp==(*jt))
                    {
                        //ans.erase(jt);
                        printf("%lld %lld\n",invtemp.first,invtemp.second);
                        break;
                    }
 
                }
 
            }
            }
        }
 
 
    }
}
