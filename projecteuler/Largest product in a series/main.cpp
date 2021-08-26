#include <iostream>

using namespace std;
char c[102][102];
int a[102][102];
int product(int pi,int pj,int i,int j,int cnt,int ans)
{
    if(cnt==13||ans==0)
        return ans;
    int maxi=0;
    for(int q=-1;q<=1;q++)
    {
        for(int w=-1;w<=1;w++)
        {
            if(q!=w&&q!=-w)
            {
                if(i+q!=pi||j+w!=pj)
                {
                    maxi=max(maxi,product(i,j,i+q,j+w,cnt+1,ans*a[i+q][j+w]));
                }
            }
        }
    }
    return maxi;
}
int main()
{
    for(int i=0;i<=101;i++)
    {
        for(int j=0;j<=101;j++)
        {
            if(j==0||j==101||i==0||i==101)
                c[i][j]='0';
            else cin>>c[i][j];
        }
    }
    for(int i=0;i<=101;i++)
        for(int j=0;j<=101;j++)
            a[i][j]=c[i][j]-'0';
    int maxi=0;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            maxi=max(maxi,product(i,j,i,j,1,a[i][j]));
        }
    }
    cout<<maxi;
    return 0;
}
