///C


#include <bits/stdc++.h>

using namespace std;
int a[110];
int main()
{
    int n;
    cin>>n;
    int tmp=0,s=0;
    vector<int> v;
    v.push_back(1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
        if(i==1)
            tmp+=a[i];
        else if(a[i]*2<=a[1])
            tmp+=a[i],v.push_back(i);
    }
    if(tmp<=s/2)
    {
        cout<<0;
        return 0;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
