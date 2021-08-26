///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5+5,inf=1e15;
pii v[maxn];
int a[maxn],dic[maxn];
int ans[maxn],c;
int num,len;
main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    len=sqrt(n);
    num=n/len-((n%len)==0);
    //cerr<<"LEN & NUM : "<<len<<" "<<num<<endl;
    for(int i=0;i<=num;i++)
        v[i].f=inf;
    for(int i=0;i<=num;i++)
        for(int j=i*len;j<min(n,i*len+len);j++)
            if(v[i].f>=a[j])
                v[i]=pii(a[j],j);

    for(int T=1;T<=n;T++)
    {
        int t,p;
        for(int i=0;i<=num;i++)
            if(v[i].f-dic[i]==0)
                t=v[i].s,p=i;
        c++;
        ans[t]=c;
        for(int i=p+1;i<=num;i++)
            dic[i]+=c;

        v[p].f=inf;
        for(int i=p*len;i<min(n,(p+1)*len);i++)
        {
            a[i]-=dic[p];
            if(i>=t)
                a[i]-=c;
            if(a[i]>=0&&v[p].f>=a[i])
                v[p]=pii(a[i],i);
        }
        dic[p]=0;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}
