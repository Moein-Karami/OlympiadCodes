///Chefer


#include <bits/stdc++.h>
#define int long long int

using namespace std;

main()
{
    int n,x,y,cntx,cnty;
    cin>>n;
    bool b;
    for(int j=1;j<=n;j++)
    {
        scanf("%lld%lld",&x,&y);
        if(x<y)
            swap(x,y);
        b=1;
        for(int i=2;i*i<=x;i++)
        {
            if((x%i==0&&y%i!=0)||(x%i!=0&&y%i==0))
            {
                i=x;
                b=0;
                continue;
            }
            else if(x%i==0&&y%i==0)
            {
                cntx=0;
                cnty=0;
                while(x%i==0)
                {
                    x/=i;
                    cntx++;
                }
                while(y%i==0)
                {
                    y/=i;
                    cnty++;
                }
                if(cntx*2<cnty||cntx>2*cnty||(cnty+cntx)%3!=0)
                {
                    b=0;
                    i=x;
                    continue;
                }
                if(x<y)
                    swap(x,y);
            }
        }
        if(x>1||!b)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}
