#include <bits/stdc++.h>

using namespace std;
int a[100000][6],o[100000][6];
const int mod=10357;
int answer[6][6];
vector <int> v;
int cnt;
int ans;
int t1[6],t2[6];
int fact[11];
int q,w;
int s[11];
void build (int x,int y)
{
    if(x==6)
    {
        cnt++;
        for(int i=1;i<=v.size();i++)
        {
            a[cnt][i]=v[i-1];
            o[cnt][i]=v[i-1];
        }
        return;
    }
    for(int i=y;i<=10;i++)
    {
        v.push_back(i);
        build(x+1,i);
        v.pop_back();
    }
}
bool check(int x,int y)
{
    bool a1=0,a2=0;
    for(int i=1;i<=5;i++)
    {
        if(a[y][i]>=2)
            a1=1;
        if(o[x][i]>=2)
            a2=1;
    }
    return min(a1,a2);
}
void clean()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            answer [i][j]=0;
}
void help(int x,int y)
{
    for(int i=1;i<=5;i++)
    {
        t2[i]=a[y][i];
        t1[i]=o[x][i];
    }
}
int maxi(int x)
{
    int maximom=0;
    if(x==1)
    {
        for(int i=1;i<=5;i++)
            maximom=max(maximom,t1[i]);
        return maximom;
    }
    else
    {
        for(int i=1;i<=5;i++)
            maximom=max(maximom,t2[i]);
        return maximom;
    }

}
int bish(int x)
{
    int ret=0,maximom=0;
    if(x==1)
    {
        for(int i=1;i<=5;i++)
        {
            if(t1[i]>maximom)
            {
                maximom=t1[i];
                ret=i;
            }
        }
    }
    else
    {
        for(int i=1;i<=5;i++)
        {
            if(t2[i]>maximom&&!answer[q][i])
            {
                maximom=t2[i];
                ret=i;
            }
        }
    }
    return ret;
}
void solve(int x,int y)
{
    clean();
    help(x,y);
    while(maxi(1)!=0&&maxi(2)!=0)
    {
        q=bish(1);
        w=bish(2);
        if(w==0)
            return;
        answer[q][w]=min(2,min(t1[q],t2[w]));
        t1[q]-=answer[q][w];
        t2[w]-=answer[q][w];
    }
    if(maxi(1)+maxi(2)>0)
        return;
    int ans1=fact[5],ans2=fact[5];

    for(int i=1;i<=10;i++)
        s[i]=0;
    for(int i=1;i<=5;i++)
        s[a[y][i]]++;
    for(int i=1;i<=10;i++)
        ans1/=fact[s[i]];

    for(int i=1;i<=10;i++)
        s[i]=0;
    for(int i=1;i<=5;i++)
        s[a[y][i]]++;
    for(int i=1;i<=10;i++)
        ans2/=fact[s[i]];
    ans+=ans1*ans2;
}
int main()
{
    fact[0]=1;
    for(int i=1;i<=10;i++)
        fact[i]=i*fact[i-1];
    build(1,0);
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            if(check(i,j))
                solve(i,j);
        }
    }
    cout<<ans%mod;
    return 0;
}
