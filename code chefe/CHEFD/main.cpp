///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e5;
int se[4*maxn][10];
int a[maxn];
map<int,int> mp;
int cnt[3];
void add(int id,int L,int R,int l,int r,int val,int tp)
{

    if(l==L&&r==R)
    {
        se[id][tp]+=val;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),val,tp);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val,tp);
}
int say(int id,int L,int R,int idx,int tp)
{
    int ret=0;
    ret+=se[id][tp];
    if(L+1==R)
        return ret;
    int mid=(L+R)/2;
    if(idx<mid)
        ret+=say(2*id,L,mid,idx,tp);
    else
        ret+=say(2*id+1,mid,R,idx,tp);
    return ret;
}
int tavan(int x,int y)
{
    int ret=1;
    int t=y;
    for(int i=0;i<35;i++)
    {
        if((1LL<<i)&x)
            ret*=t;
        t*=t;
    }
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    mp[0]=2;
    mp[1]=3;
    mp[2]=5;
    int n;
    cin>>n;
    n++;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<3;j++)
        {
            cnt[j]=0;
            while(a[i]%mp[j]==0)
            {
                cnt[j]++;
                a[i]/=mp[j];
            }
            add(1,1,n,i,i+1,cnt[j],mp[j]);
        }
        //cerr<<"I : "<<i<<endl;
        //for(int j=0;j<3;j++)
        //{
          //  cout<<"TYPE & VAL : "<<mp[j]<<" "<<say(1,1,n,i,mp[j])<<endl;
        //}cout<<endl;
    }
    int q;
    cin>>q;
    int tp;
    int l,r,t3;
    int t1,t2;
    for(int o=1;o<=q;o++)
    {
        cin>>tp;
        if(tp==1)
        {
            cin>>l>>r>>t3;
            r++;
            add(1,1,n,l,r,-1,t3);
        }
        else
        {
            cin>>t1>>t2;
            for(int j=0;j<3;j++)
            {
                cnt[j]=0;
                while(t2%mp[j]==0)
                {
                    cnt[j]++;
                    t2/=mp[j];
                }
                int tmp=say(1,1,n,t1,mp[j]);
                add(1,1,n,t1,t1+1,cnt[j]-tmp,mp[j]);
            }
            a[t1]=t2;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(say(1,1,n,i,mp[j])>0)
                a[i]*=tavan(say(1,1,n,i,mp[j]),mp[j]);
        }
        cout<<a[i]<<" ";
    }
    return 0;
}
