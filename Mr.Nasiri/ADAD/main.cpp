///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    int b;
    cin>>a>>b;
    int ans=0;
    if(a<=10000)
    {
        for(int i=1 ;i<=a;i++)
        {
            int t=i;
            while(t)
            {
                if(t%10==0)
                    ans++;
                t/=10;
            }
        }

        for(int i=1;i<=b;i++)
        {
            int t=i;
            while(t)
            {
                if(t%10==0)
                    ans--;
                t/=10;
            }
        }
    }
    else
    {
         int x=2889;
         int tmp=10000;
         ans+=(x + 4);
         while(a-10000>tmp)
         {
             //cout<<tmp<<endl;
             int t=tmp/10000;
             int y=0;
             while(t)
             {
                 if(t%10==0)
                    y++;
                 t/=10;
             }
             ans+=4000;
             ans=ans+y*10000;
             tmp+=10000;
         }
         for(int i=tmp+1;i<=a;i++)
        {
            int t=i;
            while(t)
            {
                if(t%10==0)
                    ans++;
                t/=10;
            }
        }


        tmp=1;
        if(b>10000)
            ans-=x,tmp=10000;

        while(b-10000>tmp)
         {
             int t=tmp/10000;
             int y=0;
             while(t)
             {
                 if(t%10==0)
                    y++;
                 t/=10;
             }
             ans-=x;
             ans-=1230;
             ans=ans-y*10001;
             tmp+=10000;
         }
         for(int i=tmp+1;i<=b;i++)
        {
            int t=i;
            while(t)
            {
                if(t%10==0)
                    ans--;
                t/=10;
            }
        }
    }
    cout<<ans;
    return 0;
}
