///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+10;
bool b[maxn];
int a[maxn];
int p[maxn];
queue <int> q;
int ans;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!p[i])
            q.push(i),ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        if(p[a[i]]>1)
        {
            if(b[a[i]])
            {
                p[a[i]]--;
                a[i]=q.front();
                q.pop();
            }
            else
            {
                int x=q.front();
                if(x<a[i])
                {
                    p[a[i]]--;
                    a[i]=x;
                    q.pop();
                }
                else
                {
                    b[a[i]]=1;

                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
