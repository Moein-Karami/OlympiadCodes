///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int inf=1e18,in=1e9;
main()
{
    while(1){
    pii a,b,c;
    //cin>>a.f>>a.s>>b.f>>b.s>>c.f>>c.s;
    a.f=(rand()*rand()*rand())%inf-in;
    a.s=(rand()*rand()*rand())%inf-in;
    b.f=(rand()*rand()*rand())%inf-in;
    b.s=(rand()*rand()*rand())%inf-in;
    c.f=(rand()*rand()*rand())%inf-in;
    c.s=(rand()*rand()*rand())%inf-in;
    cerr<<a.f<<endl;
    if(b.s==a.s)
    {
        int x=fabs(b.f-a.f);
        int y=(fabs(c.s-b.s));
        if(x%y!=0)
        {
            cout<<"No"<<endl;
            //return 0;
            continue;
        }
    }
    else if(a.f==b.f)
    {
        int x=fabs(b.s-a.s);
        int y=fabs(c.f-b.f);
        if(x%y!=0)
        {
            cout<<"No"<<endl;
            //return 0;
            continue;
        }
    }
    else
    {
        if(b.s-a.s!=-(c.s-b.s)||b.f-a.f!=c.f-b.f)
        {
            cout<<"No"<<endl;
            //return 0;
            continue;
        }
    }
    cout<<"Yes"<<endl;}
    return 0;
}
