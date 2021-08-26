#include <bits/stdc++.h>

using namespace std;
bool b[1010][1010];
int t1,t2;
void col(int x,int y)
{
    bool d=0;
    while(!d)
    {
        cout<<x<<" "<<y<<flush<<endl;
        cin>>t1>>t2;
        if(t1==0&&t2==0)
        {
            for(int i=-1;i<=1;i++)
                for(int j=-1;j<=1;j++)
                    b[x+i][y+j]=1;
        }
        else
            b[t1][t2]=1;
        d=1;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                d&=b[x+i][j+y];
    }
}
main()
{
    int T;
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                b[i][j]=0;
        int a;
        cin>>a;
        int x=200,y=200;
        while(a>0)
        {
            col(x,y);
            a-=9;
            x+=3;
        }
    }
    return 0;
}
