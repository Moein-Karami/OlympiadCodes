///DARK PROGRAMMER


#include <iostream>

using namespace std;
int dp[101][101];
int dp2[101][101][101];
int b[101][101];
int ans=0;
int n,k;

int solve(int i ,int j,int cnt)
{
    if(dp2[i][j][cnt])
        return dp2[i][j][cnt];
    if(cnt==k)
    {
        return 1;
    }
    if(i>n||j>n||cnt>k)
    {
        return 0;
    }

    if(b[i][j]==0)
    {
        dp[i][j]=2;
        for(int q=i-1;q<=i+1;q++)
            for(int w=j-1;w<=j+1;w++)
                b[q][w]++;
        cnt++;
        int t=j,t1=i;
        j++;
        if(j>n)
        {
            j=1;
            i++;
        }
        dp2[t1][t][cnt]+=solve(i,j,cnt);
        for(int q=t1-1;q<=t1+1;q++)
            for(int w=t-1;w<=t+1;w++)
                b[q][w]--;
        cnt--;
        solve(i,j,cnt);
        //return 0;
    }
    else
    {
        j++;
        if(j>n)
        {
            j=1;
            i++;
        }
        solve(i,j,cnt);
        //return 0;
    }
    //return 0;
}

int main()
{
    cin>>n>>k;
    solve(1,1,0);
    int x=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            x+=dp2[i][j][k];
        }
    }
    cout<<x;
    return 0;
}
