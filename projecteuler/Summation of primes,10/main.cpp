#include <iostream>

using namespace std;
int p[1000000];
int main()
{
    int ans=0;
    p[1]=2;
    p[2]=3;
    p[3]=5;
    p[4]=7;
    p[5]=11;
    int cnt=5;
    ans=28;
    bool pr=1;

    for(int i=12;i<=2000000;i++)
    {

        for(int j=1;j<=cnt;j++)
        {

            if(i%p[j]==0)
            {
                pr=0;
            }

        }
        if(pr)
        {
            cnt++;
            p[cnt]=i;
            ans+=p[cnt];
        }
        pr=1;
    }
    cout<<ans;
    return 0;
}
