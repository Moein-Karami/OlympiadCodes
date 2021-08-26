///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[2000];
char c='a';
string ans;
main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"a";
        return 0;
    }
    for(int i=1;i<=1000;i++)
        a[i]=i*(i+1)/2;
    for(int i=1000;i>=1;i--)
    {
        //cerr<<i<<endl;
        while(a[i]<=n)
        {
            n-=a[i];
            for(int j=1;j<=i+1;j++)
                ans.push_back(c);
            c++;
        }
    }
    //cerr<<"DONE"<<endl;
    cout<<ans;
    return 0;
}
