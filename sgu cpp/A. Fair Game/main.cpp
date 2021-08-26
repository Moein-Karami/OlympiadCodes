///Chefer


#include <bits/stdc++.h>

using namespace std;
int a[1000];
vector <int> v;
main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        if(a[t])
            a[t]++;
        else
        {
            a[t]++;
            cnt++;
            v.push_back(t);
        }


    }
    if(cnt!=2)
    {
        cout<< "NO";
        return 0;
    }
    if(a[v[0]]!=a[v[1]])
    {
        cout<< "NO";
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<v[0]<<" "<<v[1];
    return 0;
}
