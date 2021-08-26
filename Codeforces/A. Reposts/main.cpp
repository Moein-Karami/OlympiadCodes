///DARK PROGRAMMER


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int maxn=1e3;
map <string,int> mp1;
map <int , string> mp2;
vector <int> v[maxn];
bool b[maxn];
int h[maxn];
pair <int,int> maxi;
void dfs(int x)
{
    b[x]=1;
    for(int i=0;i<v[x].size();i++)
    {

        if(!b[v[x][i]])
        {///cout<<v[x].size()<<" "<<mp2[x]<<" "<<x<<" "<<mp2[v[x][i]]<<" "<<v[x][i]<<endl;
            h[v[x][i]]=h[x]+1;
            if(h[v[x][i]]>maxi.s)
            {
                maxi.s=h[v[x][i]];
                maxi.f=v[x][i];
            }
            dfs(v[x][i]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    string a,q,c;
    mp1["Polycarp"]=0;
    mp2[0]="Polycarp";
    for(int i=1;i<=n;i++)
    {
        cin>>a>>q>>c;
        mp1[a]=i;
        mp2[i]=a;
        cout<<mp1[c]<<endl;
        v[mp1[c]].push_back(mp1[a]);
    }
    for(int i=0;i<v[0].size();i++)
        cout<<v[0][i]<<endl;
    h[0]=1;
    cout<<endl;
    dfs(0);
    cout<<maxi.s;
    return 0;
}
