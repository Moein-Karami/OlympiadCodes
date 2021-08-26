///DARK PROGRAMMER


#include <iostream>
#define int long long int
using namespace std;
int chefer(int a , int n)
{
    int tmp=1;
    if(n==1)
        return a;
    else if(n%2==0)
    {
        tmp=chefer(a,n/2);
        return tmp*tmp;
    }
    else
    {
        tmp=chefer(a,n/2);
        return tmp*tmp*a;
    }

}
main()
{

    int a,n;
    cin>>a>>n;
    int ans=chefer(a,n);
    cout<<ans;
    return 0;
}
