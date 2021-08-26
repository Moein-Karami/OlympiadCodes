#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[10][10];
int ans;
void check()
{
    for(int i=2;i<=6;i++)
    {
        for(int j=2;j<=6;j++)
        {
            set<int> se;
            se.insert(a[i-1][j]);
            se.insert(a[i-1][j-1]);
            se.insert(a[i][j-1]);
            if(se.size()!=3)
                return;
            for(int k=1;k<=4;k++)
            {
                se.insert(k);
                if(se.size()==4)
                {
                    a[i][j]=k;
                    break;
                }
            }
        }
    }
    if(a[2][6]!=2||a[5][2]!=4||a[6][4]!=4)
        return ;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)
            cerr<<a[i][j]<<" ";
        cerr<<endl;
    }cerr<<endl;
    //getchar();
    ans++;
}
void build(int x,int y)
{
    if(y>6)
        x++,y=1;
    else if(x>1&&y>1)
        y=1,x++;
    if(x==7)
    {
        check();
        return;
    }
    if(x==1&&y==3)
    {
        a[x][y]=3;
        y++;
        build(x,y);
        return;
    }
    else if(x==2)
    {
        a[x][y]=1;
        y++;
        build(x,y);
        return;
    }
    for(int i=1;i<=4;i++)
    {
        a[x][y]=i;
        build(x,y+1);
    }
}
main()
{
    build(1,1);
    cout<<ans;
    return 0;
}
