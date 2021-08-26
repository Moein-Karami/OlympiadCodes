#include <iostream>
#include <vector>

using namespace std;

unsigned int sum[10000];

bool nprime[1000000];

vector <long long unsigned int> prime(0);

int main()
{
    long long unsigned  n , siz , cnt=0 , i , j , k ;
    cin>>n;
    nprime[1]=true;
    for( i=1;i<= n ;i++)
    {
        if(!nprime[i])
            for( j=i*i ;j<n ; j+=i )
            nprime[j]=true;
    }

    for( i=1; i<=n ;i++)
        if(!nprime[i])
        prime.push_back(i);

    siz=prime.size();

    for( i=1 ; i<=siz ; i++)
    {
            if(2+prime[i]==prime[i+1]||2+prime[i]==prime[i+2])
            {
                cnt++;
                sum[cnt]=prime[i];
            }
    }
    cout<<cnt<<endl;
    for( i=1;i<=cnt;i++)
    {
        cout<<"2"<<" " <<sum[i]<<endl ;
    }

    return 0;
}

