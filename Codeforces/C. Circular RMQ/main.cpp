///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5,inf=1e9;
int se[4*maxn];
int lazy[4*maxn];
void pakhsh(int id)
{
    se[2*id]+=lazy[id];
    se[2*id+1]+=lazy[id];
    lazy[2*id]+=lazy[id];
    lazy[2*id+1]+=lazy[id];
    lazy[id]=0;
}
void add(int id,int L,int R,int l,int r,int val)
{
    pakhsh(id);
    if(L==l&&r==R)
    {
        lazy[id]+=val;
        se[id]+=val;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(mid,r),val);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val);
    se[id]=min(se[2*id],se[2*id+1]);
}
int say(int id,int L,int R,int l,int r)
{
    pakhsh(id);
    if(L==l&&r==R)
        return se[id];
    int ret=inf;
    int mid=(L+R)/2;
    if(l<mid)
        ret=min(ret,say(2*id,L,mid,l,min(mid,r)));
    if(r>mid)
        ret=min(ret,say(2*id+1,mid,R,max(l,mid),r));
    return ret;
}
int tp(string s)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
        if(s[i]==' ')
            cnt++;
    return cnt;
}
main()
{
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        add(1,0,n,i,i+1,t);
    }
    int m;
    cin>>m;
    string s;
    int a[3];
    getline(cin,s);
    for(int i=0;i<m;i++)
    {
        a[0]=0;
        a[1]=0;
        a[2]=0;
        getline(cin,s);
        int h=tp(s);
        if(h==1)
        {
            int cnt=0;
            for(int j=0;j<s.size();j++)
            {
                while(s[j]!=' '&&j<s.size())
                {
                    a[cnt]=10*a[cnt]+(s[j]-'0');
                    j++;
                }
                cnt++;
            }
            if(a[0]>a[1])
                cout<<min(say(1,0,n,a[0],n),say(1,0,n,0,a[1]+1))<<endl;
            else
                cout<<say(1,0,n,a[0],a[1]+1)<<endl;
        }
        else
        {
            int cnt=0;
            bool man=0;
            for(int j=0;j<s.size();j++)
            {
                while(s[j]!=' '&&j<s.size())
                {
                    if(s[j]=='-')
                    {
                        man=1;
                        j++;
                    }
                    a[cnt]=10*a[cnt]+(s[j]-'0');
                    j++;
                }
                cnt++;
            }
            if(man)
                a[2]=-a[2];
            if(a[0]>a[1])
                add(1,0,n,a[0],n,a[2]),add(1,0,n,0,a[1]+1,a[2]);
            else
                add(1,0,n,a[0],a[1]+1,a[2]);
        }
    }
    return 0;
}
