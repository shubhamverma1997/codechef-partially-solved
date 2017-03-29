#include<iostream>
using namespace std;
//some problem with lpd
//int divi[1000]={1,1,2,3,2,5,2,7,2,3,2,11,2,13,2,3,2,17,2,19,20};
int main()
{
    //for(int i=0;i<50;i++)
    //    cout<<divi[i]<<" ";
    long int t,m,n,a[100001],x,y,z,result;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        cin>>m;
 
        for(register long int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(register int long i=0;i<m;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            scanf("%d",&z);
            if(x==0)
            {
                for(register long int j=y-1;j<z;j++)
                    a[j]=1;
            }
 
            else
            {
                result=1;
                for(register long int j=y-1;j<z;j++)
                    if(result<a[j])
                    result=a[j];
                cout<<result<<" ";
            }
        }
        cout<<endl;
        t--;
    }
}
 
