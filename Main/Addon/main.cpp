#include <bits/stdc++.h>

using namespace std;
vector <int> ans;
bool b[30100],c[30100];
int a[10100];
int main()
{

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],c[a[i]]=1;
    sort(a+1,a+n+1);
    for(int i=a[1];i<=20020;i+=a[1])
        b[i]=1;
    int t=a[1];
    ans.push_back(a[1]);

    for(int i=a[1];i<=20020;i++)
    {
        if(b[i]&&!c[i])
            break;
        if(c[i]&&!b[i])
        {
            ans.push_back(i);
            b[i]=1;
            for(int j=1;j<=20020;j++)
            {
                if(b[j])
                {
                    b[j+i]=1;
                }
            }
        }
        t=i;
    }
    cout<<t<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
