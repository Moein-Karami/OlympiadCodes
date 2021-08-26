///DARK PROGRAMMER



#include <iostream>
#define int long long int
int a,b,n,mod=1e9+7;
using namespace std;


int cheferz(int a,int p)
{
    int tmp=1;
    if(p==1)
        return a;
    else if(n%2==0)
    {
        tmp=cheferz(a,p/2);
        return tmp*tmp;
    }
    else
    {
        tmp=cheferz(a,p/2);
        return tmp*tmp*a;
    }
}
int chefert(int x,int a)
{
    return (x*cheferz( a, mod-2))%mod;
}
//int chefer(int i)
//{
  //  if(i==0)
    //    return 1;
    //return (chefert((n-i+1)*chefer(i-1),i))%mod;
//}


main()
{
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        cin>>a>>b>>n;
        int sum=0,ans=0;
        for(int i=0;i<=n;i++)
        {
            sum=i*b+(n-i)*a;
            bool c=1;
            int t=sum;
            while(t)
            {
                if(t%10!=a&&t%10!=b)
                    c=0;
                t/=10;
                if(!c)
                    t=0;
            }
            if(c)
            {
                int tmp=i;
                if(tmp>n/2)
                    tmp=n-tmp;
                int tmpans=1;
                for(int j=1;j<=i;j++)
                {
                    tmpans=(chefert((n-i+1)*tmpans,i))%mod;
                }
                ans+=tmpans;
                ans=ans%mod;
            }
        }
        cout<<ans;
    }

    return 0;
}
