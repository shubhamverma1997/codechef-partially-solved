#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
 
unordered_map<long long int ,long long int> dc;
 
long long int func(vector<long long int> v,long long int index,long long int score)
{
  vector<long long int> indices;
  if(dc[v[index]]!=0)
  {
    //cout<<"in"<<v[index]<<endl;
    //cout<<"cought "<<v[index]<<" "<<dc[v[index]]<<"<--";
    
    return dc[v[index]]+score+1;
  }
  else
  {
    //cout<<"loose "<<v[index]<<" "<<endl;
    long long int counter=0;
    for(register long long int i=index;i<v.size();i++)
    {
      if(i==index)
      {
        continue;
      }
      
      if(v[index]%v[i]==0)
      {
        indices.push_back(i);
        counter++;
      }
    }
    if(counter==0)
      return score+1;
    long long int mx=-1;
    //cout<<"v[index]="<<v[index]<<" ";
    for(register long long int i=0 ; i<counter;i++)
    {
      //cout<<"in "<<i<<" ";
      mx=max(mx,func(v,indices[i],score+counter+1));
    }
    //cout<<endl;
    dc[v[index]]=mx-score-1;
    return mx;
  }
}
 
 
int main()
{
  dc[1]=0;
  long long int a,b,score=0,temp,ans=0,ft;
  scanf("%lld",&a);
  scanf("%lld",&b);
  vector<long long int> div1,div2;
  vector<long long int>::iterator it;
  for(register long long int i=a;i<=b;i++)
  {
    //dc.clear();
    for(register long long int j=1;j*j<=i;j++)
    {
      if(i%j==0)
        {
          div1.push_back(j);
          if(j!=(i/j))
            div2.push_back(i/j);
        }
    }
    it=div1.end()-1;
    for(it;it!=div1.begin();it--)
    {
      div2.push_back(*it);
    }
    div2.push_back(1);
    
    /*for(it=div2.begin();it!=div2.end();it++)
    {
      cout<<*it<<" ";
    }*/
 
    //cout<<endl<<endl;
    ft=func(div2,0,0);
    
    ans+=ft-1;
    
 
    div1.clear();
    div2.clear();
    //cout<<endl<<endl;
 
  }
  cout<<ans;
}
