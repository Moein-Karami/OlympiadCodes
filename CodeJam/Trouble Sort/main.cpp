#include <bits/stdc++.h>
#define int long long int
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];
int t[maxn];
map<int,int> mp;
int com[maxn];
int id[maxn][3];
main()
{
    int T;
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        mp.clear();
        int n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            id[i][0]=0,id[i][1]=0;;
        for(int i=0;i<n;i++)
            cin>>a[i],t[i]=a[i];
        sort(t,t+n);
        for(int i=0;i<n;i++)
            if(!mp[t[i]])
                cnt++,mp[t[i]]=cnt;
        for(int i=0;i<n;i++)
            a[i]=mp[a[i]],id[a[i]][i%2]++;
        cnt=0;
        int b=-1;
        for(int i=1;i<=n;i++)
        {
            while(id[i][0]||id[i][1])
            {
                if(id[i][cnt%2]==0)
                {
                    b=cnt;
                    break;
                }
                else
                    id[i][cnt%2]--,cnt++;
            }
            if(b!=-1)
                break;
        }
        cout<<"Case #"<<Q<<": ";
        if(b!=-1)
            cout<<b<<"\n";
        else cout<<"OK\n";
    }
    return 0;
}
