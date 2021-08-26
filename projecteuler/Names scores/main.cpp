#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans,cnt;
main()
{
    fstream fp("Names scores.txt",ios::in);
    if(!fp)
    {
        cout<<"File can not open!"<<endl;
        exit(1);
    }
    string s;
    char c ;
    while(fp>>c)
    {
        s.push_back(c);
    }
    int t;
    for(int i=0;i<s.size();i++)
    {
        t=0;
        if(s[i]=='"')
        {
            cnt++;
            i++;
            while(s[i]!='"')
            {
                t+=s[i]-'A'+1;
                i++;
            }
            ans+=cnt*t;
        }
    }
    cout<<ans;
    return 0;
}
