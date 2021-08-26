///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector <int> v[10];
vector <int> tmp;
pii a[100];
bool b[110];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f>>a[i].s;
        v[a[i].f].push_back(i);
        if(a[i].f!=a[i].s)
            v[a[i].s].push_back(i);
    }
    int t=0;
    for(int i=0;i<7;i++)
        if(v[i].size()%2)
            t++,tmp.push_back(i);
    if(t>2)
    {
        cout<<"No solution";
        return 0;
    }
    b[v[tmp[0]][0]]=1;
    int p=v[tmp[0]][0];
    if(a[p].f==tmp[0])
        cout<<p<<" +";
    else
        cout<<p<<" -",swap(a[p].f,a[p].s);
    cout<<endl;
    int k=a[p].s;
    v[0].remove(1);
    for(int i=2;i<n;i++)
    {
        p=v[k][0];
        if(a[p].f==k)
            cout<<p<<" +"
    }
    return 0;
}
