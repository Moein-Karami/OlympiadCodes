///DARK PROGRAMMRE


#include <iostream>

using namespace std;

int bg[10000];
int n;
int chefer(int i,int b, int j)
{
    if(i==n-1)
        return ((10*b)+bg[i])%j;
    else
    {
        b=(10*b+bg[i])%j;
        return chefer(i+1,b,j);
    }
}
int main()
{
    int m,t;
    int a;
    string s;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            bg[j]=0;
        }
        cin>>a>>s;
        if(!a)
        {
            cout<<s<<endl;
            continue ;
        }

        n=s.size();
        for(int j=0;j<n;j++)
            bg[j]=s[j]-48;
        bool b=0;
        int ans;
        for(int j=a;j>=1;j--)
        {
            if(a%j==0&&chefer(0,0,j)==0)
            {
                b=1;
                ans=j;
                break;
            }
        }
        if(b)
            cout<<ans<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
