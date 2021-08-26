#include <iostream>

using namespace std;

int main()
{
    for(int i=10;i<=1000000;i++)
    {
        int n=i;
        int cnt=0,tmp=n;
        for(int i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                cnt++;
                while(tmp%i==0)
                    tmp/=i;
            }
        }
        if(tmp>1)
            cnt++;
        if(cnt!=4)
            continue;
        n++;
        cnt=0;
        tmp=n;
        for(int i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                cnt++;
                while(tmp%i==0)
                    tmp/=i;
            }
        }
        if(tmp>1)
            cnt++;
        if(cnt!=4)
            continue;
            n++;
        cnt=0;
        tmp=n;
        for(int i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                cnt++;
                while(tmp%i==0)
                    tmp/=i;
            }
        }
        if(tmp>1)
            cnt++;
        if(cnt!=4)
            continue;
            n++;
        cnt=0;
        tmp=n;
        for(int i=2;i*i<=tmp;i++)
        {
            if(tmp%i==0)
            {
                cnt++;
                while(tmp%i==0)
                    tmp/=i;
            }
        }
        if(tmp>1)
            cnt++;
        if(cnt!=4)
            continue;
            cout<<i<<endl;
    }
    return 0;
}
