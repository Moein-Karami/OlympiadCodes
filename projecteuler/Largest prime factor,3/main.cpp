#include <iostream>

using namespace std;
int prime[10000000];
int main()
{
    long long int x=600851475143,ans ,cnt=5;
    prime[1]=2;
    prime[2]=3;
    prime[3]=5;
    prime[4]=7;
    prime[5]=11;
    bool p=1,p2=1;;
    for(int i=12;i<=x/2;i++)
    {
        if(x%i==0)
        {
            for(int j=1;j<=cnt;j++)
            {
                 if(i%prime[j]==0)
                    p=0;
            }
            if(p)
            {
                ans=i;
                cout<<"<<"<<ans<<">>"<<endl;
            }

            p=1;
        }

        for(int j=1;j<=cnt;j++)
            if(i%prime[j]==0)
                p2=0;
        if(p2)
        {
            cnt++;
            prime[cnt]=i;
        }
        p2=1;
    }
    cout<<ans;
    return 0;
}
