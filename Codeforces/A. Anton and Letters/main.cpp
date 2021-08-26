#include <iostream>

using namespace std;
char s2[1010];
int main()
{
    int cnt=0;
    bool b;
    string x;
    while(x[1]!='}'&&x[2]!='}')
    {
        cin>>x;
        int n=x.size();
        for(int i=0;i<n;i++)
        {
            b=1;
           for(int j=0;j<cnt;j++)
           {
               if(x[i]==s2[j])
                b=0;
           }
           if(b)
           {
               s2[cnt]=x[i];
               cnt++;
           }
        }
        if(x[0]=='{'&&x[2]=='}')
            cnt=4;
    }
    if(cnt-3<0)
        cnt=3;

    cout<<cnt-3;
    return 0;
}
