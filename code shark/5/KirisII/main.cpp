#include <bits/stdc++.h>

using namespace std;
int mod=10753;
int ans[10][10];
vector <int> v[7];
void dfs(int x,int y)
{
    ans[x][y]=1;
    //cerr<<"X&Y : "<<x<<" "<<y<<endl;
    for(int i=0;i<v[y].size();i++)
        if(!ans[x][v[y][i]])
            dfs(x,v[y][i]);

}
int main()
{
    int a=0;
    int n;
    cin>>n;
    for(int i=1;i<(1<<(n*n));i++)
    {
        if(__builtin_popcount(i)<=11)
        {
            for(int j=0;j<=n;j++)
                for(int k=0;k<=n;k++)
                    ans[j][k]=0,v[j].clear();
            bool b=1;
            //cerr<<"I : "<<i<<endl;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if((1<<(j*n+k))&i)
                    {
                        //cerr<<"J&K : "<<j<<" "<<k<<endl;
                        v[j].push_back(k);
                        if(j==k)
                            b=0;
                    }
                }
            }
            //cerr<<"I : "<<i<<endl;
            for(int j=0;j<n;j++)
                dfs(j,j);
            //cerr<<i<<" "<<b<<endl;
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(!ans[j][k]&&j!=k)
                        b=0;
            a+=b;
        }
    }
    cout<<a%mod<<endl;
    return 0;
}
