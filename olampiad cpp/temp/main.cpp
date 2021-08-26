#include <iostream>

using namespace std;

int main()
{
    #include <iostream>
#include <vector>

using namespace std;

#define f first ;
#define s second ;

bool nprime[10000];
vector <int> prime(0);

vector <pair<int[],int> > t(0);

int main()
{
    int n , siz , x;
    cin>>n ;
    for(int i=2 ; i<=n ;i++ )
    {
        if(!nprime[i])
        {
            for(int j=i*i;j<=n ; j+=i)
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
            t.push_back(prime[i],0);
            while(n!=1 && n%prime[i]==0)
            {
            n=n/i;
            t[i].s ++ ;
            }
        }
    }

    siz=t.size();
    for(int i=0 ; i<siz ; i++)
        cout<< t[i] << endl;
    return 0;
}
    return 0;
}
