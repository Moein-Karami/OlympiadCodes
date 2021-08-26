#include <iostream>

using namespace std;
int t[200],ch[200];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=t[i];j<=n;j++)
        {
            if(ch[j]==0)
                ch[j]=t[i];
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
        cout<<ch[i]<<" ";
    return 0;
}
