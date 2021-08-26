#include <bits/stdc++.h>
#define vs v.size()
using namespace std;
const int maxn=1000000;
bool b[2*maxn];
vector <int> v;
int a[maxn+10];
main()
{
    for(int i=1;i<=maxn;i++)
    {
        a[i]++;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                a[i]+=j;
                if(j*j!=i)
                    a[i]+=i/j;
            }
        }
    }
    int maxi=0;
    int ans=0;
    for(int i=1;i<=maxn;i++)
    {

        for(int j=0;j<vs;j++)
            b[v[j]]=0;
        v.clear();
        v.push_back(i);
        bool c=1;
        while(vs-1==0||v[vs-1]!=v[0])
        {
            if(b[v[vs-1]]||v[vs-1]>maxn)
            {
                c=0;
                v[vs-1]=v[0];
                break;
            }
            b[v[vs-1]]=1;
            v.push_back(a[v[vs-1]]);
        }
        if(c&&vs>maxi)
        {

            maxi=vs;
            ans=maxn+10;
            for(int j=0;j<vs;j++)
                ans=min(ans,v[j]);
        }

    }
    cout<<ans;
    return 0;
}
