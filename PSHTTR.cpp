//using stack
#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#define ll long long int
using namespace std;

pair<ll,ll> parent[100005];

int main()
{
	long long int t,n,m,u,v,c,k,ans,temp;
	
	vector< pair< ll,ll > > *tree;

	scanf("%lld",&t);

	while(t)
	{
		
		scanf("%lld",&n);
		tree=new vector< pair< ll,ll > >[n+1];
		
		for(register ll i=0;i<n-1;i++)
		{
			scanf("%lld",&u);
			scanf("%lld",&v);
			scanf("%lld",&c);
			tree[u].push_back(make_pair(v,c));
			tree[v].push_back(make_pair(u,c));
		}

		scanf("%lld",&m);

		for(register ll i=0;i<m;i++)
		{
			ans=0;
			scanf("%lld",&u);
			scanf("%lld",&v);
			scanf("%lld",&k);

			//queue<ll> q;
			stack<ll> q;
			long long int flag=0;
			q.push(u);
			parent[u]=make_pair(-1,-1);
			while(!q.empty())
			{
				temp=q.top();
				q.pop();
				//cout<<temp<<endl;
				vector< pair< ll,ll > >::iterator it;
				for(it=tree[temp].begin();it!=tree[temp].end();it++)
				{
					if(v==(*it).first)
					{
						parent[(*it).first]=make_pair(temp,(*it).second);
						flag=1;
						break;
					}
					if(parent[temp].first!=(*it).first)
					{
						parent[(*it).first]=make_pair(temp,(*it).second);
						q.push((*it).first);
					}
				}
				if(flag==1)
					break;
					
			}

			/*for(register long long int i=1;i<n+1;i++)
			{
				cout<<parent[i].first<<" "<<parent[i].second<<"|";
			}
			cout<<endl;
			*/
			temp=v;

			//cout<<"----------------";
			while(temp!=-1)
			{
				//cout<<parent[temp].second<<" ";
				if(parent[temp].second<=k && parent[temp].first!=-1)
					ans=ans^parent[temp].second;
				temp=parent[temp].first;
			}
			//cout<<endl;
			cout<<ans<<endl;

		}


		t--;
	}
}
