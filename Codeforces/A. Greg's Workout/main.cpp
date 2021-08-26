#include <iostream>

using namespace std;

int main()
{
    int n,b=0,s=0,p=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%3==1)
            s+=a[i];
        if(i%3==2)
            b+=a[i];
        if(i%3==0)
            p+=a[i];
    }
    int maxi=max(s,p);
    maxi=max(maxi,b);
    if(maxi==s)
        cout<< "chest";
    if(maxi==b)
        cout<< "biceps" ;
    if(maxi==p)
        cout<< "back" ;
    return 0;
}
