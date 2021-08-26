#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,x;
        cin>>n>>x;
        int maxh=0,maxd=0;
        for(int j=1;j<=n;j++)
        {
            int t1,t2;
            cin>>t1>>t2;
            maxd=max(maxd,t1-t2);
            maxh=max(maxh,t1);
        }
        x-=maxh;
        if(x<=0)
        {
            cout<<1<<endl;
            continue;
        }
        if(maxd<=0)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<1+x/maxd+((x%maxd)!=0)<<endl;
    }
    return 0;
}
