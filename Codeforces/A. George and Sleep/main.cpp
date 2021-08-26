///DARK PROGRAMMER


#include <iostream>

struct hour
{
    int h,m;
    char c;
};
using namespace std;

int main()
{
    hour a,b;
    cin>>a.h>>a.c>>a.m;
    cin>>b.h>>b.c>>b.m;
    int ans=0;
    while(a.h!=b.h||a.m!=b.m)
    {
        ans++;
        b.m++;
        b.h+=(b.m/60);
        b.m%=60;
        b.h%=24;
    }
    int h=ans/60;
    if(h/10==0)
        cout<<0;
    cout<<h<<":";
    ans%=60;
    if(ans/10==0)
        cout<<0;
    cout<<ans;
    return 0;
}
