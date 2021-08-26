///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
double a[2000];
bool mark[2000];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool b=1;
    double x=a[2]-a[1];
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=x)
            b=0;
    if(b)
    {
        cout<<"No";
        return 0;
    }
    double y=a[2];
    bool c=1;
    for(int i=2;i<n;i++)
        if(y!=a[i])
            c=0;
    if(c)
    {
        if(a[1]==y&&a[n]!=y)
        {
            cout<<"Yes";
            return 0;
        }
        else if(a[n]==y&&a[1]!=y)
        {
            cout<<"Yes";
            return 0;
        }
    }

    double o=a[3]-a[2];
    bool p=1;
    for(int i=4;i<=n;i++)
    {
        if(a[i]-a[i-1]!=o)
            p=0;
    }
    if(p)
    {
        cout<<"Yes";
        return 0;
    }
    if(n==3)
    {
        cout<<"Yes";
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
            mark[j]=0;
        mark[1]=1;
        double t1=a[i]-a[1];
        double t2=i-1;
        double mk=t1/t2;
        int tmp=i;
        mark[i]=1;
        vector<int> v;
        for(int j=i+1;j<=n;j++)
        {
            double t=tmp;
            if((a[j]-a[tmp])/(j-t)==mk)
            {

                mark[j]=1;
                tmp=j;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(!mark[j])
            {
                //if(i==3)
                    //cerr<<j<<endl;
                v.push_back(j);
            }

        }
        if(v.size()<=1)
        {
            cout<<"Yes";
            return 0;
        }
        double t3=a[v[1]]-a[v[0]];
        double t4=v[1]-v[0];

        double mk2=t3/t4;
        if(mk!=mk2)
            continue;
        bool g=1;
        for(int j=2;j<v.size();j++)
        {
            if((a[v[j]]-a[v[j-1]])/(v[j]-v[j-1])!=mk2)
            {
                g=0;
            }
        }
        if(g)
        {
            cerr<<v.size()<<endl;
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
