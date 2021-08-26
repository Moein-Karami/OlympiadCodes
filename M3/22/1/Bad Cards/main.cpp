#include <bits/stdc++.h>

using namespace std;
bool b[1000000000];
int mod=10009;
main()
{
    vector<string> v;
    for(int i=1;i<=10;i++)
    {
        string s;
        int t=i;
        while(t)
        {
            if(t%2)
                s+='1';
            else
                s+='0';
            t/=2;
        }
        reverse(s.begin(),s.end());
        v.push_back(s);
        cout<<s<<endl;
    }
    int ans=(1<<29);
    int mini=1000000000,maxi=0;
    do{
        int x=0;
        for(int i=0;i<v.size();i++)
        {
            //cerr<<v[i]<<" ";
            for(int j=0;j<v[i].size();j++)
                x=x*2+v[i][j]-'0';
        }//cerr<<endl<<endl;
        //getchar();
        mini=min(x,mini);
        maxi=max(x,maxi);
        ans-=1-b[x];
        b[x]=1;
    }while(next_permutation(v.begin(),v.end()));
    cout<<"MINI : "<<mini<<endl;
    mini%=mod;
    maxi%=mod;
    ans%=mod;
    cout<<(maxi*mini)%mod<<"   "<<(ans*ans)%mod;
    return 0;
}
