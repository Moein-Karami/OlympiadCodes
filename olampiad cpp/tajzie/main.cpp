#include <iostream>
#include <vector>

using namespace std;

bool nprime[10000];
vector <int> prime(0);

pair<int,int> t[10000];

int main()
{
    nprime[1]=true;
    int n , siz , x;
    cin>>n ;
    for(int i=1 ; i<=n ;i++ )
    {
        if(!nprime[i])
        {
            for(int j=i*i ; j<=n ; j=j+i)
            {
                nprime[j]=true;
            }
        }
    }
    for(int i=2 ; i<=n ; i++)
        if(!nprime[i])
            prime.push_back(i);

    siz=prime.size();

    for(int i=0 ; i<siz ; i++)
    {
        if(n%prime[i]==0)
        {
            t[i].first=prime[i];
            while(n!=1 && n%prime[i]==0)
            {
            n=n/prime[i];
            t[i].second ++ ;
            }
        }
    }


    for(int i=0 ; i<=siz ; i++)
        {
            if(t[i].first!=0)
            {
                cout<<t[i].first<<"  "<<t[i].second<<endl;
            }
        }
    return 0;
}
