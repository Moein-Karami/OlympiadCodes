#include <iostream>

using namespace std;

int main()
{
    int s1=0,s2=0,n,a;
    for(int i=1;i<=3;i++)
    {
        cin>>a;
        s1+=a;
    }
    for(int i=1;i<=3;i++)
    {
        cin>>a;
        s2+=a;
    }
    cin>>n;
    int ans=0;
    if(s1%5==0)
        ans+=s1/5;
    else
        ans+=s1/5+1;
    if(s2%10==0)
        ans+=s2/10;
    else
        ans+=s2/10+1;
    if(ans<=n)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
