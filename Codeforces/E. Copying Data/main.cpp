///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
const int maxn=4e5;
int a[maxn],b[maxn];
int se[4*maxn];
int tim[4*maxn];
int cnt;
void change(int id,int L,int R,int l,int r,int x)
{
    if(L==l&&r==R)
    {
        se[id]=x;
        tim[id]=cnt;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        change(2*id,L,mid,l,min(r,mid),x);
    if(r>mid)
        change(2*id+1,mid,R,max(l,mid),r,x);
}
int say(int id,int L,int R,int idx,int t)
{
    if(L+1==R)
    {
        if(tim[id]>t)
            return a[idx+se[id]];
        else
            return 1e10;
    }
    int ret=1e10;
    if(tim[id]>t)
    {
        ret=a[idx+se[id]];
    }
    int mid=(L+R)/2;
    int tmp;
    if(idx<mid)
        tmp=say(2*id,L,mid,idx,max(t,tim[id]));
    else
        tmp=say(2*id+1,mid,R,idx,max(t,tim[id]));
    if(tmp==1e10)
        return ret;
    else
        return tmp;

}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<n;j++)
        cin>>b[j];
    int h,ans;
    int la,lb,x;
    int tmp;
    for(int o=1;o<=q;o++)
    {
        cin>>h;
        if(h==1)
        {
            cnt++;
            cin>>la>>lb>>x;
            la--;
            lb--;
            change(1,0,n,lb,lb+x,la-lb);
        }
        else
        {
            cin>>h;
            h--;
            ans=b[h];
            tmp=say(1,0,n,h,0);
            if(tmp!=1e10)
                ans=tmp;
            cout<<ans<<endl;
        }
    }

    return 0;
}
