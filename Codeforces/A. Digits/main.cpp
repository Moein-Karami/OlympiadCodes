///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<n;i++)
        t+=s[i]-'0';
    int tmp=0;
    while(t)
    {
        tmp+=t%10;
        t/=10;
    }
    while(t)
    {
        t+=tmp%10;
        t/=10;
    }
    if(t>=10)
    {
        cout<<-1;
        return 0;
    }
    ///
    t=0;
    tmp=0;
    t+=s[0]-'0';
    cout<<s[0];
    for(int i=1;i<n;i++)
        cout<<"+"<<s[i],t+=s[i]-'0';cout<<endl;
    vector <int>num;
    while(t)
    {
        tmp+=t%10;
        num.push_back(t%10);
        t/=10;
    }
    if(num.size()==0)
        num.push_back(0);
    cout<<num[num.size()-1];
    if(num.size()>1)
        for(int i=num.size()-2;i>=0;i--)
            cout<<"+"<<num[i];
    cout<<endl;
    num.clear();
    t=tmp;
    tmp=0;
    while(t)
    {
        tmp+=t%10;
        num.push_back(t%10);
        t/=10;
    }
    if(num.size()==0)
        num.push_back(0);
    cout<<num[num.size()-1];
    if(num.size()>1)
        for(int i=num.size()-2;i>=0;i--)
            cout<<"+"<<num[i];
    cout<<endl;
}
