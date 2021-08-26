#include <iostream>

using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        int maxi=max(s1[i]-48,s2[i]-48),mini=min(s1[i]-48,s2[i]-48);
        ans+=min(maxi-mini,mini+9-maxi+1);
    }
    cout<<ans;
    return 0;
}
