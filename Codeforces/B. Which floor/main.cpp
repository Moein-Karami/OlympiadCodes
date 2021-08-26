///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[700];
main()
{
    int n,m;
    cin>>n>>m;
    int maxi=n;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1]=t2;
        //if(t1==n)
        //{
          //  cout<<t2;
           // return 0;
        //}
        maxi=max(maxi,t1);
    }
    vector <int> ans;
    for(int i=1;i<=maxi+3;i++)
    {
        bool b=1;
        for(int j=1;j<=maxi+3;j+=i)
        {
            for(int k=j;k<=min((j+i-1),maxi+3);k++)
                if(a[k]!=0&&a[k]!=k/i+(k%i!=0))
                    b=0;
        }
        if(b)
            ans.push_back(i);
    }
    if(ans.size()==0)
    {
        cout<<-1;
        return 0;
    }
    int x=ans[0];
    int t=n/x+(n%x!=0);
    bool b=1;
    for(int i=1;i<ans.size();i++)
        if(t!=n/ans[i]+(n%ans[i]!=0))
            b=0;
    if(!b)
    {
        cout<<-1;
        return 0;
    }
    cout<<t;
    return 0;
}
