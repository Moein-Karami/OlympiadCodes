#include <bits/stdc++.h>
#define int long long unsigned int
using namespace std;
int a[]={1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,0};
void build(int x)
{
    //cerr<<x<<endl;
    //getchar();
    if(x==19)
    {
        int s=0;
        for(int i=0;i<19;i++)
            s=s*10+a[i];
        int sq=sqrt(s);
        if(sq*sq==s)
        {
            cout<<sq<<" "<<s;
            exit(0);
        }
        return ;
    }
    for(int i=0;i<10;i++)
    {
        a[x]=i;
        build(x+2);
    }
}
main()
{
    build(1);
    return 0;
}
