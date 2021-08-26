///DARK PROGRAMMER



#include <iostream>

using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int t;
    cin>>t;
    for(int i=1;i<n;i++)
        cin>>a[i];
    int ans=1;
    a[n]=1;
    while(ans<=n)
    {
        if(ans==t)
        {
            cout<<"YES";
            return 0;
        }
        ans+=a[ans];
    }
    cout<<"NO";
    return 0;
}
