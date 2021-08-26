///DARK PROGRAMMER


#include <iostream>

using namespace std;
bool c[15][15];
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    string s[n];

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        bool b=1;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='S')
                b=0;
        }
        if(b)
        {
           ans+=m;
           for(int j=0;j<m;j++)
                c[i][j]=1;
        }
    }
    for(int j=0;j<m;j++)
    {
        bool b=1;
        for(int i=0;i<n;i++)
        {
            if(s[i][j]=='S')
                b=0;
        }
        if(b)
        {
           for(int i=0;i<n;i++)
            {
                if(!c[i][j])
                {
                    ans++;
                    c[i][j]=1;
                }
            }
        }
    }
    //for(int i=0;i<n;i++)
    //{
      //  for(int j=0;j<m;j++)
        //    cout<<c[i][j]<<" ";
        //cout<<endl;
    //}
    cout<<ans;

    return 0;
}
