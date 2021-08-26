#include <bits/stdc++.h>

using namespace std;
bool b[1010];
main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int t=k;
    int n=s.size();
    for(int i=0;i<s.size();i++)
    {
        if(!t)
            break;
        int maxi=0;
        for(int j=i;j<=min(n-1,i+t);j++)
        {
            while(b[j])
                j++;
            if(j>=n)
                break;
            maxi=max(maxi,s[j]-'0');
        }
        int cnt=0;
        for(int j=i;j<=min(n-1,i+t);j++)
        {
            while(b[j])
                j++;
            if(j>=n)
                break;
            if(s[j]-'0'!=maxi)
            {
                cnt++;
                b[j]=1;
            }
            else
                j=i+t+1;
        }
        t-=cnt;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(!t)
            break;
        if(!b[i])
        {
            b[i]=1;
            t--;
        }
    }
    for(int i=0;i<n;i++)
        if(!b[i])
            cout<<s[i];
    return 0;
}
