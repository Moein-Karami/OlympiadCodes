#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6;
vector <int> v[maxn];
int main()
{
    for(int i=2;i<maxn;i++)
    {
        if(!v[i].size())
        {
            for(int j=i;j<maxn;j+=i)
                v[j].push_back(i);
        }
    }
    for(int i=2;i<maxn;i++)
    {
        if(v[i].size()==4&&v[i].size()==v[i+1].size()&&v[i].size()==v[i+2].size()&&v[i].size()==v[i+3].size())
        {

            for(int )
        }
    }
    return 0;
}
