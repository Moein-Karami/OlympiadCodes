#include <iostream>
using namespace std;
bool a[100000+100][10];
int m[10];
int x,k;
int main()
{
    cin>>x>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>m[i];
        m[i]+=m[i-1];
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i][j-1])
                a[i][j]=1;
            if(i>m[j])
            if(i%m[j]==0||a[i-m[j]][j])
                a[i][j]=1;
        }
    }
    if(a[x][k])
        cout<<"YES";
    else
        cout<<"NO";
}

