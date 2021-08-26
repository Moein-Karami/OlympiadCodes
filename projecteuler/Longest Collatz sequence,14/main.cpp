#include <iostream>

using namespace std;

int main()
{
    int x=0,t=0,f=0;
    for(int i=1000000;i>1;i--)
    {
        t=0;
        int n=i,cnt=0;
        while(n!=1)
        {
            if(n>1000000)
                t++;
            if(n%2==0)
                n/=2;
            else
                n=3*n+1;
            cnt++;
            if(t==2)
                n=1;
        }

        if(t!=2)
        if(x<=cnt)
        {
            x=cnt;
            f=i;
        }


    }
    cout<<f;
    return 0;
}
