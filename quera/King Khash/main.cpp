///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=80;
bitset<maxn> bit[80];
string s[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<n;j++)
            bit[i][j]=s[i][j]-'0';
        bit[i][i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(bit[i]==(1<<n)-1)
        {
            cout<<1<<endl<<i;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bitset<maxn>tmp=bit[i]|bit[j];
            if(tmp==(1<<n)-1)
            {
                cout<<2<<endl<<i<<" "<<j;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                bitset<maxn>tmp=bit[i]|bit[j]|bit[k];
                if(tmp==(1<<n)-1)
                {
                    cout<<3<<endl<<i<<" "<<j<<" "<<k;
                    return 0;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int q=k+1;q<n;q++)
                {
                    bitset<maxn>tmp=bit[i]|bit[j]|bit[k]|bit[q];
                    if(tmp==(1<<n)-1)
                    {
                        cout<<4<<endl<<i<<" "<<j<<" "<<k<<" "<<q;
                        return 0;
                    }
                }
            }
        }
    }
}
