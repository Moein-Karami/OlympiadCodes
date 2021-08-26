///C


#include <bits/stdc++.h>

using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    string s,t,p;
    int cnt[410];
    int T;
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        cin>>s>>t>>p;
        int q=0;
        for(int i=0;i<400;i++)
            cnt[i]=0;
        for(int i=0;i<p.size();i++)
            cnt[p[i]]++;
        bool b=1;
        for(int i=0;i<t.size();i++)
        {
            if(q!=s.size())
            {
                if(s[q]==t[i])
                    q++;
                else
                {
                    if(cnt[t[i]])
                        cnt[t[i]]--;
                    else
                        b=0;
                }
            }
            else
            {
                if(cnt[t[i]])
                        cnt[t[i]]--;
                else
                        b=0;
            }
            if(!b)
                break;
            //cerr<<"I : "<<i<<" "<<b<<endl;
        }
        if(b&&(q==s.size()))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
