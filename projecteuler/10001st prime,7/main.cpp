#include <iostream>

using namespace std;

int main()
{
    bool b=1;
    int cnt=1,n=2;
    while(cnt<10002)
    {
        for(int i=2;i<n/2+1;i++)
            if(n%i==0)
                b=0;
        if(b)
            cnt++;
        n++;
        b=1;
    }
    cout<<n-1;
    return 0;
}
