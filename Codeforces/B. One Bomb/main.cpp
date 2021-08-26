#include <iostream>
#include <string>
using namespace std;
int sotoon[1010],radif[1010];
bool b;
int x,y;
int main()
{
    int n,m;
    cin>>n>>m;
    string str[1010];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(str[i][j]=='*')
            {
                cnt++;
                radif[i]++;
            }

    }
    ///
    //cout<<"_______________________"<<endl;
    //for(int i=0;i<n;i++)
    //{
     //   for(int j=0;j<m;j++)
     //       cout<<str[i][j];
     //   cout<<endl;

    //}
    ///
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
            if(str[i][j]=='*')
            {
                sotoon[j]++;
            }

    }
    //cout<<radif[0]+sotoon[9];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(radif[i]+sotoon[j]==cnt&&str[i][j]!='*')
            {
                cout<<"YES"<<endl<<i+1<<" "<<j+1;
                return 0;
            }
            else if(str[i][j]=='*'&&radif[i]+sotoon[j]-1==cnt)
            {
                x=i+1;
                y=j+1;
                b=1;
            }
        }

    }
    if(b==0)
    cout<<"NO";
    else
    {
        cout<<"YES"<<endl<<x<<" "<<y;
                return 0;
    }
    return 0;
}
