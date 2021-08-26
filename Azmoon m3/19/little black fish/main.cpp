#include <bits/stdc++.h>

using namespace std;
bool b[10][10];
int ans;
void clean()
{
    for(int i=0;i<=4;i++)
        for(int j=0;j<=4;j++)
            b[i][j]=0;
}
int check(int i,int j)
{
    if(i==4&&j==4)
        return 1;
    int ret=0;
    if(b[i+1][j])
        ret=check(i+1,j);
    if(b[i][j+1])
        ret+=check(i,j+1);
    return ret;
}
int main()
{
    for(int i=0;i<(1<<25);i++)
    {
        clean();
        for(int j=0;j<25;j++)
            if(i&(1<<j))
                b[j/5][j%5]=1;
        if(b[0][0]&&check(0,0)==1)
            ans++;
    }
    cout<<ans%10099;
    return 0;
}
