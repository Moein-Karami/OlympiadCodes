#include <iostream>

using namespace std;
int a[1000][1000],c[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int maxi=0,win;

    for(int i=0;i<m;i++)
    {
        maxi=-1;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]>maxi)
            {
                maxi=a[i][j];
                win=j;
            }
        }
        c[win]++;//cout<<"J";
    }

    maxi=0;
    for(int i=0;i<n;i++)
        if(c[i]>maxi)
            maxi=c[i];
    for(int i=0;i<n;i++)
    {
        if(c[i]==maxi)
            {
                cout<<i+1;
                return 0;
            }
    }

    return 0;
}
