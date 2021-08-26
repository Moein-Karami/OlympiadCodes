///Expert



#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string a,c;
    int ans=0;
    bool b=0;
    cin>>n;
    cin>>a>>c;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=c[i])
        {
            if(!b)
            {
                ans++;
                b=1;
            }
        }
        else
        {
            b=0;
        }
    }
    cout<<ans;
    return 0;
}
