#include <bits/stdc++.h>

using namespace std;
int ans;
const int mod=10711;
main()
{

    vector <int> v,a,b;
    for(int i=1;i<=7;i++)
        v.push_back(i);
    do{
        a.clear();
        b.clear();
        for(int i=0;i<7;i++)
            a.push_back(v[i]);
        for(int i=1;i<=4;i++)
        {
            if(i%2==1)
            {
                b.clear();
                b.push_back(a[0]);
                for(int j=1;j<a.size();j++)
                    if(a[j]>a[j-1])
                        b.push_back(a[j]);
            }
            else
            {
                a.clear();
                a.push_back(b[0]);
                for(int j=1;j<b.size();j++)
                    if(b[j]>b[j-1])
                        a.push_back(b[j]);
            }
        }
        if(a.size()==1&&a[0]==7)
            ans++;
        else if(b.size()==1&&b[0]==7)
            ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<(ans*ans*ans)%mod;
    return 0;
}
