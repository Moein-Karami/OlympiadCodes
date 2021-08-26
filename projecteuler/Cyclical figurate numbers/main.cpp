#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e5+5;
int a[10][maxn];
bool b[maxn],c[10];
int ans[10];
void solve(int x,int y)
{
    //cerr<<"X & Y : " <<x<<" "<<y<<endl;
    if(ans[3]==8128)
    {
        cerr<<"X & Y : "<<x<<" "<<y<<" "<<endl;
        for(int i=3;i<x;i++)
            cerr<<ans[i]<<" ";
        cerr<<endl;
    }//*/

    if(x==9)
    {
        int s=0;
        for(int i=3;i<9;i++)
        {
            s+=ans[i];
            cerr<<ans[i]<<" ";
        }
        cerr<<endl<<s;
        exit(0);
    }
    if(y<10)
        return ;
    y*=100;
    for(int i=10;i<100;i++)
    {
        if(x==8&&ans[3]/100!=i)
            continue;
        y+=i;
        for(int j=3;j<=8;j++)
        {
            if(a[j][y]&&!c[j]&&!b[a[j][y]])
            {
                c[j]=1;
                b[a[j][y]]=1;
                ans[x]=y;
                solve(x+1,i);
                c[j]=0;
                b[a[j][y]]=0;
            }
        }
        y-=i;
    }
}
main()
{
    int s;
    for(int i=1;i<=1000;i++)
    {
        s=i*(i+1)/2;
        if(s<maxn)
            a[3][s]=i;
        s=i*i;
        if(s<maxn)
            a[4][s]=i;
        s=i*(3*i-1)/2;
        if(s<maxn)
            a[5][s]=i;
        s=i*(2*i-1);
        if(s<maxn)
            a[6][s]=i;
        s=i*(5*i-3)/2;
        if(s<maxn)
            a[7][s]=i;
        s=i*(3*i-2);
        if(s<maxn)
            a[8][s]=i;
    }
    ///cerr<<a[5][2882]<<endl;
    for(int i=1000;i<=maxn-5;i++)
    {
        for(int j=3;j<=8;j++)
        {
            if(a[j][i])
            {
                b[a[j][i]]=1;
                c[j]=1;
                ans[3]=i;
                solve(4,i%100);
                b[a[j][i]]=0;
                c[j]=0;
            }
        }
    }
    return 0;
}
