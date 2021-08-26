#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10357;
int f[21],ans;
vector <vector <int> > v;
void build(vector <int> t,int x,int y)
{
    if(x==6)
    {
        bool c=0;
        for(int i=0;i<5;i++)
            if(t[i]>=2)
                c=1;
        if(c)
            v.push_back(t);
        return;
    }
    for(int i=y;i<=10;i++)
    {
        t.push_back(i);
        build(t,x+1,i);
        t.pop_back();
    }
}
bool check(vector<int> ta,vector <int> tb)
{
    int b[5];
    for(int i=0;i<5;i++)
        b[i]=tb[i];
    sort(b,b+5);
    int a[5];
    int t1=0,t2=0;
    for(int i=0;i<5;i++)
    {
         a[i]=ta[i];
         t1+=a[i];
         t2+=b[i];
    }
    if(t2!=t1)
        return 0;
    for(int i=4;i>=0;i--)
    {
        sort(a,a+5);
        int j=4;
        while(b[i]>0)
        {
            if(j<0)
            {
                 for(int q=0;q<5;q++)
                    cout<<tb[q]<<" ";
                cout<<" ";
                for(int q=0;q<5;q++)
                    cout<<ta[q]<<" ";
                cout<<endl;
                return 0;
            }

            if(a[j]>1&&b[i]>1)
            {
                b[i]-=2;
                a[j]-=2;
            }
            else
            {
                b[i]--;
                a[j]--;
            }
            j--;
        }
    }
    for(int i=0;i<=4;i++)
    {
        if(b[i]!=0||a[i]!=0)
        {
            for(int q=0;q<5;q++)
                cout<<tb[q]<<" ";
            cout<<" ";
            for(int q=0;q<5;q++)
                cout<<ta[q]<<" ";
            cout<<endl;
            return 0;
        }
    }
    return 1;
}
int fact(vector<int> t)
{
    int a[11];
    for(int i=0;i<11;i++)
        a[i]=0;
    for(int i=0;i<5;i++)
        a[t[i]]++;
    int ret=f[5];
    for(int i=0;i<11;i++)
        ret/=f[a[i]];
    return ret;
}
main()
{
    f[0]=1;
    for(int i=1;i<=20;i++)
        f[i]=(f[i-1]*i)%mod;
    vector <int> t;
    for(int i=0;i<=10;i++)
    {
        t.push_back(i);
        build(t,2,i);
        t.pop_back();
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(check(v[i],v[j]))
                ans=(ans+fact(v[i])*fact(v[j]))%mod;
        }
    }
    cout<<ans%mod;
    return 0;
}
