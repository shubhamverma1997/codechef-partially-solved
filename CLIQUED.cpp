#include<iostream>
#include<limits>
#include<unordered_map>
#include<utility>
#include<vector>
using namespace std;
class minheap
{
public:
 
  pair<long long int,long long int> *arr;//node,distance
  unordered_map <long long int,long long int> ma;
  long long int capacity;
  long long int current_size;
  minheap(long long int c)
  {
    capacity=c;
    current_size=0;
    arr=new pair<long long int,long long int>[c];
  }
  void add(long long int distance)//for cc question element is the distance
  {
    if(current_size==capacity)
    {
      return;
    }
    //ma[current_size]=INT_MAX;//current node has infinite distance from
                            //selected node
    current_size++;
    arr[current_size-1]=make_pair(current_size,numeric_limits<long long int>::max());
    ma[current_size]=current_size-1;
    //current node has infinite distance from selected node
 
    long long int i=current_size-1;
    while(i!=0 && arr[i].second<arr[(i-1)/2].second)
    {
      pair<long long int,long long int> temp=arr[i];
      ma[arr[i].first]=(i-1)/2;
      ma[arr[(i-1)/2].first]=i;
      arr[i]=arr[(i-1)/2];
      arr[(i-1)/2]=temp;
      i=(i-1)/2;
    }
  }
 
  pair<long long int,long long int>  extract()
  {
    if(current_size<=0)
    {
      return make_pair(numeric_limits<long long int>::max(),
                      numeric_limits<long long int>::max());
    }
    if(current_size==1)
    {
      current_size--;
      return arr[0];
    }
 
    pair<long long int,long long int> root=arr[0];
    current_size--;
    ma.erase(arr[0].first);
    arr[0]=arr[current_size];
    ma[arr[current_size].first]=0;
    minheapify(0);
 
    return root;
  }
 
  void minheapify(long long int index)
  {
    long long int left=2*index+1,right=2*index+2,smallest=index;
    if(left<current_size && arr[left].second<arr[index].second)
      smallest=left;
    if(right<current_size && arr[right].second<arr[smallest].second)
      smallest=right;
    if(index!=smallest)
    {
      pair<long long int,long long int> temp=arr[smallest];
      ma[arr[smallest].first]=index;
      ma[arr[index].first]=smallest;
      arr[smallest]=arr[index];
      arr[index]=temp;
      minheapify(smallest);
    }
  }
  void decrease(long long int node,long long int value)
  {
    long long int index=ma[node];
    arr[index].second=value;
 
    while(index!=0 && arr[index].second<arr[(index-1)/2].second)
    {
      ma[arr[index].first]=(index-1)/2;
      ma[arr[(index-1)/2].first]=index;
      pair<long long int,long long int> temp=arr[index];
      arr[index]=arr[(index-1)/2];
      arr[(index-1)/2]=temp;
      index=(index-1)/2;
    }
    minheapify(0);
 
  }
  bool isempty()
  {
    if(current_size==0)
      return true;
    else
      return false;
  }
 
};
int main()
{
  /*
  long long int distance[100002];
  minheap m(5);
  m.add(6);
  m.add(2);
  m.add(10);
  m.add(12);
  m.add(4);
  for(int i=0;i<5;i++)
  {
    cout<<i<<" "<<m.arr[i].first<<" "<<m.arr[i].second<<endl;
  }
  for(int i=1;i<6;i++)
  {
    cout<<m.ma[i]<<endl;
  }
  cout<<endl<<endl;
  m.decrease(4,1);
  for(int i=0;i<5;i++)
  {
    cout<<i<<" "<<m.arr[i].first<<" "<<m.arr[i].second<<endl;
  }
  for(int i=1;i<6;i++)
  {
    cout<<m.ma[i]<<endl;
  }*/
  long long int t,n,k,x,m,s,a,b,c;
  scanf("%lld",&t);
  while (t)
  {
    vector<long long int> edges[100001],weight[100001];
    long long int dist[100002];
    scanf("%lld",&n);
    minheap mh(n);
    scanf("%lld",&k);
    scanf("%lld",&x);
    scanf("%lld",&m);
    scanf("%lld",&s);
    for(register long long int i=0;i<n;i++)
    {
      mh.add(0);
    }
    mh.decrease(s,0);
    dist[s]=0;
    for(register long long int i=0;i<m;i++)
    {
      scanf("%lld",&a);
      scanf("%lld",&b);
      scanf("%lld",&c);
      edges[a].push_back(b);
      weight[a].push_back(c);
      edges[b].push_back(a);
      weight[b].push_back(c);
    }
    pair<long long int,long long int> temp;
    vector<long long int>::iterator it,jt;
    while(!mh.isempty())
    {
      //cout<<endl;
      //for(int i=0;i<mh.current_size;i++)
      //{
        //cout<<i<<" "<<mh.arr[i].first<<" "<<mh.arr[i].second<<endl;
      //}
      //cout<<"}"<<endl;
      temp=mh.extract();
      dist[temp.first]=temp.second;
      //cout<<temp.second<<"! ";
      if(!edges[temp.first].empty())
      {
        for(it=edges[temp.first].begin(),jt=weight[temp.first].begin()
            ;it!=edges[temp.first].end(),jt!=weight[temp.first].end()
            ;it++,jt++)
        {
          if(mh.arr[mh.ma[(*it)]].first!=(*it))
            continue;
          //cout<<"(1)";
          //cout<<" -"<<temp.first<<"|"<<(*it)<<"|"<<(*jt)<<"- ";
          if(dist[temp.first]+(*jt) < mh.arr[mh.ma[(*it)]].second)
          {
 
            //cout<<dist[temp.first]+(*jt)<<"** ";
            //cout<< mh.arr[mh.ma[(*it)]].second<<"// ";
            mh.decrease((*it),dist[temp.first]+(*jt));
            //cout<< mh.arr[mh.ma[(*it)]].second<<"++ ";
          }
 
        }
      }
      if(temp.first<=k) // if old city
      {
        for(register long long int i=1;i<=k;i++)
        {
          if(mh.arr[mh.ma[(i)]].first!=(i))
            continue;
          //cout<<"(2)";
          //cout<<" -"<<temp.first<<"|"<<i<<"|"<<x<<"- ";
          if(x+dist[temp.first] < mh.arr[mh.ma[i]].second)
          {
            //cout<<x<<"** ";
            //cout<< mh.arr[mh.ma[i]].second<<"// ";
            mh.decrease(i,x+dist[temp.first]);
            //cout<< mh.arr[mh.ma[i]].second<<"++ ";
          }
        }
      }
    }
    for(register long long int i=1;i<=n;i++)
    {
      printf("%lld ",dist[i]);
    }
    printf("\n");
    t--;
  }
 
 
}
