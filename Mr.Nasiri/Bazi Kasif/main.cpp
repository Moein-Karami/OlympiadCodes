///DARK PROGRAMMER


#include <bits/stdc++.h>

using namespace std;
int n;
string s;
bool check()
{
    bool c=0;
    for(int i=0;i<n-1;i++)
        if(s[i]=='A'&&s[i+1]=='B')
            c=1;
    return c;
}
int main()
{
    cin>>n;
    s+='A';
    for(int i=1;i<=n-2;i++)
        s+='.';
    s+='B';
    int h;
    int sum=2;
    while(n)
    {
        cout<<s<<endl;
        if(check())
        {
            cout<<"SOOKHTI :)";
            return 0;
        }
        cin>>h;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
            {
                s[i]='.';
                s[i+h]='A';
                break;
            }
        }
        if(check())
        {
            cout<<s<<endl;
            cout<<"SOOKHTAM :(";
            return 0;
        }
        if((n-sum)%3==0)
        {
            sum+=3;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='B')
                {
                    s[i-3+h]='B';
                    s[i]='.';
                    break;
                }
            }
        }
        else if(n-sum-h==1)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='B')
                {
                    s[i-1]='B';
                    s[i]='.';
                    break;
                }
            }
            if(check())
            {
                cout<<s<<endl;
                cout<<"SOOKHTI :)";
                return 0;
            }
        }
        else if(n-sum-h==2)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='B')
                {
                    s[i-2]='B';
                    s[i]='.';
                    break;
                }
            }
            if(check())
            {
                cout<<s<<endl;
                cout<<"SOOKHTI :)";
                return 0;
            }
        }
        else
        {
            sum+=h;
            if((n-sum)%3==1)
            {
                h+=2;
                for(int i=n-1;i>=0;i++)
                {
                    if(s[i]=='B')
                    {
                        s[i-2]='B';
                        s[i]='.';
                        break;
                    }
                }
            }
            else
            {
                h+=1;
                for(int i=n-1;i>=0;i++)
                {
                    if(s[i]=='B')
                    {
                        s[i-1]='B';
                        s[i]='.';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
