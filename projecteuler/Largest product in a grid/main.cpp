#include <iostream>

using namespace std;
int a[22][22];
int product(int pi,int pj,int i,int j,int cnt,int ans)
{
    int maxi=0;
    if(cnt==4)
        return ans;
    for(int q=-1;q<=1;q++)
    {
        for(int w=-1;w<=1;w++)
        {
            if(w!=0||q!=0)
            {
                if(i+q!=pi||j+w!=pj)
                {
                    if(a[i+q][j+w]!=0)
                        maxi=max(maxi,product(i,j,i+q,j+w,cnt+1,ans*a[i+q][j+w]));
                }
            }
        }
    }
    return maxi;
}
int main()
{
    int ans=0;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
            cin>>a[i][j];
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            ans=max(ans,product(i,j,i,j,1,a[i][j]));
        }
    }
    cout<<ans;
    return 0;
}
