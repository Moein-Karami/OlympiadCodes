///DARK PROGRAMMER


#include <iostream>
#include <vector>
#define int long long int

using namespace std;
vector <int> a;
vector <int> t;
main()
{
    int s=-1;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl<<0;
        return 0;
    }
    bool c=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            c=0;
    }
    if(c)
    {
        cout<<1<<endl<<0;
        return 0;
    }

    int tmp=n;
    for(int i=2;i*i<=n;i++)
    {
        if(tmp%i==0)
        {
            a.push_back(i);
            s++;
            t.push_back(0);
        }
        while(tmp%i==0)
        {
            tmp/=i;
            t[s]++;
        }
    }
    if(tmp!=1)
    {
       a.push_back(tmp);
       t.push_back(1);
    }
    int m=a.size();
    if(m==2&&t[0]==1&&t[1]==1)
    {
        cout<<2;
        return 0;
    }
    cout<<1;
    int ans=1;
    ans=a[0]*a[1];
    cout<<endl<<ans;
    return 0;
}
