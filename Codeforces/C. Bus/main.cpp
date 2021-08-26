///Chefer


#include <bits/stdc++.h>

using namespace std;
int ans;
main()
{
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int x=b;
    bool p=0;
    if(k==1)
    {
        if(a-f>b||f>b)
        {
            cout<<-1;
            return 0;
        }
        if(a>b)
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    if(k==2)
    {
        if(f>b||b<2*(a-f))
        {
            cout<<-1;
            return 0;
        }
        for(int i=1;i<=k-1;i++)
        {
            if(!p)
            {
                if(a+(a-f)>x)
                {
                    ans++;
                    x=b-(a-f);
                }
                else
                {
                    x-=a;
                }
                p=1;
            }
            else
            {
                if(a+(f)>x)
                {
                    ans++;
                    x=b-f;
                }
                else
                {
                    x-=a;
                }
                p=0;
            }
        }
        if(x<a)
            ans++;
        cout<<ans;
        return 0;
    }
    if(2*(a-f)>b||2*f>b)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=k-1;i++)
    {
        if(!p)
        {
            if(a+(a-f)>x)
            {
                ans++;
                x=b-(a-f);
            }
            else
            {
                x-=a;
            }
            p=1;
        }
        else
        {
            if(a+(f)>x)
            {
                ans++;
                x=b-f;
            }
            else
            {
                x-=a;
            }
            p=0;
        }
    }
    if(x<a)
        ans++;
    cout<<ans;
    return 0;
}
