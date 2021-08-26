#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+6;
int a[maxn];
stack <int> s;
char tmp[26];
int main()
{
    tmp[0]='a';
    for(int i=1;i<26;i++)
        tmp[i]=tmp[i-1]+1;
    char c;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        a[i]=c-'a';
    }
    s.push(a[0]);
    for(int i=1;i<n;i++)
    {
        if(s.size()>0&&s.top()==a[i])
        {
            s.pop();
        }
        else
            s.push(a[i]);
    }

    string ans;
    while(s.size())
    {
        ans.push_back(tmp[s.top()]);
        s.pop();
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}
