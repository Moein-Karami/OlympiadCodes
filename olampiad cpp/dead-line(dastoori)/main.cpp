#include <iostream>
#include <cstdlib>
using namespace std;

pair<int,int> baze[10000];

int main()
{
    int n , s=0 , m=0;
    cin>>n ;
    for(int i=0 ; i<n ; i++)
    {
        cin>>baze[i].second;
        cin>>baze[i].first;
    }
    sort(baze[0],baze[n]);

    for (int i=0 ; i<n ; i++)
    {
        s+=baze[i].second;
        if(m<s-baze[i].first)
            m=s-baze[i].first;
    }
    cout<<m;
    return 0;
}
