#include <iostream>

using namespace std;
bool b[82];
int ans[82];
const int mod=10687;
void clean()
{
    for(int i=0;i<82;i++)
        b[i]=0;
}
bool check()
{
    int ret=0;
    for(int i=1;i<=81;i++)
        if(!b[i])
        ret++;
    if(ret==1)
        return 0;
    else
        return 1;
}
int main()
{

    for(int i=1;i<=81;i++)
    {
        clean();
        int t=i-1;
        while(check())
        {
            for(int j=1;j<=23;j++)
            {
                t++;
                if(t==82)
                    t=1;
                if(b[t])
                    j--;
            }
            b[t]=1;
        }
        for(int j=1;j<=81;j++)
            if(!b[j])
                ans[i]=j;
    }
    int ret=0;
    for(int i=1;i<=81;i++)
    {
        if(ans[i]==53)
            ret=i;
    }


    int answer=1;
    for(int i=1;i<=1390;i++)
        answer=(answer*ret)%mod;
        cout<<answer;
    return 0;
}
