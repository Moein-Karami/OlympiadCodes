#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    fflush(stdout);
    for(int i=1;i<=n;i++)
        s.push_back('0');
    cout<<"? "<<s<<endl;
    fflush(stdout);
    int x;
    cin>>x;
    int ans0=1,ans1=2;
    s[0]='1';
    cout<<"? "<<s<<endl;
    fflush(stdout);
    s[0]='0';
    int t;
    cin>>t;
    if(t<x)
    {
        ans1=1;
        for(int i=0;i<n;i++)
            s[i]='1';
        cout<<"? "<<s<<endl;
        fflush(stdout);
        cin>>x;
        int l=0,r=n;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            for(int i=l;i<mid;i++)
                s[i]='0';
            cout<<"? "<<s<<endl;
            fflush(stdout);
            cin>>t;
            for(int i=l;i<mid;i++)
                s[i]='1';
            if(x+mid-l!=t)
                r=mid;
            else
                l=mid;
        }
        ans0=l+1;
    }
    else
    {
        ans0=1;
        int l=0,r=n;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            for(int i=l;i<mid;i++)
                s[i]='1';
            cout<<"? "<<s<<endl;
            fflush(stdout);
            cin>>t;
            for(int i=l;i<mid;i++)
                s[i]='0';
            if(x+mid-l!=t)
                r=mid;
            else
                l=mid;
        }
        ans1=l+1;
    }
    cout<<"! "<<ans0<<" "<<ans1<<endl;
    fflush(stdout);
    return 0;
}
