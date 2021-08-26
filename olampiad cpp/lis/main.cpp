#include <iostream>

using namespace std;

int a[10000];
int dp[10000];

int add(int);

int main()
{
    int n , x=0,b=0  ;
    cin >> n;
    for (int i=0 ; i<n ; i++)
    {
        cin>>a[i];
        if(a[i]>x)
            x=a[i];
    }
    for (int i=0 ; i<n ; i++ )
    {
        dp[a[i]]=1+add(i);
    }

    for(int i=0 ; i<=x ; i++)
        if(dp[i]>b)
        b=dp[i];
    cout<<b;
    return 0;
}

int add(int i)
{
    int s=0 ;
    for (int j=a[i]-1 ; j>=0 ; j--)
    {
        if(dp[j]>s)
            s=dp[j];
    }

    return s ;
}
