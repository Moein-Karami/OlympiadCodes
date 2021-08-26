#include <iostream>

using namespace std;
int f[100];
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    bool c=1;
    for(int i=1;i<=n;i++)
    {
        bool b=0;
        int q;
        cin>>q;
        for(int j=1;j<=q;j++)
        {
            int a;
            cin>>a;
            if(a<m)
                b=1;
        }
        if(b)
        {
            f[cnt]=i;
            c=0;
            cnt++;
        }

    }
    if(c)
        cout<<0;
    else
        {
            cout<<cnt<<endl;
            for(int i=0;i<cnt;i++)
                cout<<f[i]<<" ";
        }
    return 0;
}
