#include <iostream>

using namespace std;
bool b[200];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<x;j++)
        {
            int q;
            cin>>q;
            b[q]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(!b[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
