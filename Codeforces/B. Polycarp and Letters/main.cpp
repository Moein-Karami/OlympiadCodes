///Chfere


#include <bits/stdc++.h>

using namespace std;
bool b[50];
int ans;
main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int t1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]<'a')
        {
            int t=0;
            for(int j=0;j<40;j++)
                b[j]=0;
            for(int j=t1;j<i;j++)
                if(!b[s[j]-'a'])
                    t++,b[s[j]-'a']=1;
            ans=max(t,ans);
        }
        while(s[i]<'a'&&i<n)
        {
            i++;
            t1=i;
        }
    }

        int t=0;
        for(int j=0;j<40;j++)
            b[j]=0;
        for(int j=t1;j<n;j++)
            if(!b[s[j]-'a'])
                t++,b[s[j]-'a']=1;
        ans=max(t,ans);
    cout<<ans;
    return 0;
}
