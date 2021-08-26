#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;
typedef pair<int,int> pii;
int mod=10009;
const int maxn=1e5;
int x[maxn+5],y[maxn+5],f[maxn];

main()
{
    int e,tmp,u=0;
    for(int i=1;i<=maxn;i++)
    {
        e=0;
        tmp=i;
        while(tmp%2==0)
            tmp/=2,e++;
        u=(u+e)%4;
        x[i]=x[i-1];
        y[i]=y[i-1];
        if(u==0)
            y[i]+=tmp;
        else if(u==1)
            x[i]+=tmp;
        else if(u==2)
            y[i]-=tmp;
        else if(u==3)
            x[i]-=tmp;
        if(x[i]==-66||y[i]==-666016)
        {
            cout<<i+1<<endl;
        }
        f[i]=u;
    }
    int t1,t2;
    int s1,s2;
    int r=-66,c=-666016;
    for(int i=2;i<=maxn;i++)
    {
        //cerr<<"I : "<<i<<endl;
        for(int j=1;j<i;j++)
        {
            t1=x[i]-x[j];
            t2=y[i]-y[j];
            if(f[j]==2)
                t1*=-1,t2*=-1;
            if(f[j]==1)
            {
                swap(t1,t2);
                t1*=-1;
            }
            if(f[j]==3)
            {
                swap(t1,t2);
                t2*=-1;
            }
            s1=t1;
            s2=t2;
            if(x[j-1]==r-t1&&y[j-1]<=c-t2)
            {
                cout<<i<<" "<<j<<"  "<<(i*i)%mod;
                return 0;
            }
            swap(t1,t2);
            t2*=-1;
            if(y[j-1]==c-t2&&x[j-1]<=r-t1)
            {
                cout<<i<<" "<<j<<"  "<<(i*i)%mod;
                return 0;
            }
            t1=s1*-1;
            t2=s2*-1;
            if(x[j-1]==r-t1&&y[j-1]>=c-t2)
            {
                cout<<i<<" "<<j<<"  "<<(i*i)%mod;
                return 0;
            }
            t1=s1;
            t2=s2;
            swap(t1,t2);
            t1*=-1;
            if(y[j-1]==c-t2&&x[j-1]>=r-t1)
            {
                cout<<i<<" "<<j<<"  "<<(i*i)%mod;
                return 0;
            }
        }
    }
    return 0;
}
