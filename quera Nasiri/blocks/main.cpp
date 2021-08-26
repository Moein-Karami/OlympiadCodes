#include <iostream>

using namespace std;
int a[111111],sl[111111],sr[111111],maxl[111111],maxr[111111];
int main()
{
    int n;
    cin>>n;
    sl[-1]=0;
    sr[n]=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(sl[i-1]+a[i]<0)
            sl[i]=0;
        else
            sl[i]=sl[i-1]+a[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(sr[i+1]+a[i]<0)
            sr[i]=0;
        else
            sr[i]=sr[i+1]+a[i];

    }
    for(int i=0;i<n;i++)
    {
        if(maxl[i-1]>sl[i])
            maxl[i]=maxl[i-1];
        else
            maxl[i]=sl[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(maxr[i+1]>sr[i])
            maxr[i]=maxr[i+1];
        else
            maxr[i]=sr[i];
    }
    int maxi=0;
    maxr[n]=0;
    for(int i=0;i<n;i++)
        if(maxl[i]+maxr[i+1]>maxi)
            maxi=maxl[i]+maxr[i+1];
    cout<<maxi;
    return 0;
}
