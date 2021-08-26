#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e9+6;
bool b[maxn];
vector<int> v;
bool c(int x,int y)
{
    int t=1;
    int tmp=y;
    while(tmp)
    {
        t*=10;
        tmp/=10;
    }
    return b[x*t+y];
}
bool check(int x,int y)
{
    if(c(x,y)||c(y,x))
        return 1;
    return 0;
}
main()
{
    b[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!b[i])
        {
            //if(!check(i,3)&&!check(i,7)&&!check(i,109)&&!check(i,673))
            //{
              //  cerr<<i<<endl;
            //}
            if(i<9000)
                v.push_back(i);
            for(int j=i*i;j<maxn;j+=i)
                b[j]=1;
        }
    }
    /*for(int i=2;i<10000;i++)
    {
        if(!b[i])
        {
            if(!check(i,3)&&!check(i,7)&&!check(i,109)&&!check(i,673))
                cerr<<i<<endl;
        }
    }*/
    cerr<<"FUCK"<<endl;
    for(int i=1;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            if(check(v[i],v[j]))
                continue;
            for(int k=j;k<v.size();k++)
            {
                if(check(v[i],v[k]))
                    continue;
                if(check(v[k],v[j]))
                    continue;
                for(int l=k;l<v.size();l++)
                {
                    if(check(v[i],v[l]))
                        continue;
                    if(check(v[l],v[j]))
                        continue;
                    if(check(v[l],v[k]))
                        continue;
                    //cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<v[l]<<" "<<v[i]+v[j]+v[k]+v[l]<<endl;
                    for(int q=l;q<v.size();q++)
                    {
                        if(check(v[i],v[q]))
                            continue;
                        if(check(v[q],v[j]))
                            continue;
                        if(check(v[q],v[k]))
                            continue;
                        if(check(v[l],v[q]))
                            continue;
                        cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<v[l]<<" "<<v[q]<<" "<<v[i]+v[j]+v[k]+v[l]+v[q]<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
