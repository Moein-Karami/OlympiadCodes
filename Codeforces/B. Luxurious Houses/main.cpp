///DARK PROGRAMMER


#include <iostream>
#include <cmath>

using namespace std;
long int s[1000000];
long int a[1000000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]>s[i+1])
            s[i]=a[i];
        else
            s[i]=s[i+1];
    }
    for(int i=1;i<=n;i++)
    {
        long int ans=s[i+1]-a[i];
        if(ans<0)
            cout<<0<<" ";
        else if(ans==0)
            cout<<1<<" ";
        else
            cout<<s[i]-a[i]+1<< " ";
    }
    return 0;
}
