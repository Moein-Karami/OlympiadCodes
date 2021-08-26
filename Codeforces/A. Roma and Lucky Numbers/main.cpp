///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int m=s.size();
        int cnt=0;
        for(int j=0;j<m;j++)
            if(s[j]=='4'||s[j]=='7')
                cnt++;
        if(cnt<=k)
            ans++;
    }
    cout<<ans;
    return 0;
}
