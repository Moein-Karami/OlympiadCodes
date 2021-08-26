#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
set<pii> se;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        t*=-1;
        se.insert(pii(t,i));
    }
    set<pii>::iterator x;
    pii tmp;
    pii t2;
    while(se.size())
    {
        vector <pii> v;
        x=se.begin();
        tmp=*x;
        se.erase(x);
        while(tmp.f)
        {
            tmp.f++;
            x=se.begin();
            t2=*x;
            se.erase(x);
            t2.f++;
            cout<<tmp.s<<" "<<t2.s<<"\n";
            v.push_back(t2);
        }
        for(int j=0;j<v.size();j++)
            if(v[j].f)
                se.insert(v[j]);
    }
    return 0;
}
