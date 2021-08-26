///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
int ans[520][5];
int main()
{
    int answer=1;
    int t[5];
    t[1]=8;
    t[2]=2;
    t[3]=4;
    t[4]=6;
    ans[1][1]=1;
    ans[1][2]=1;
    ans[1][3]=1;
    ans[1][4]=1;
    for(int i=2;i<=501;i++)
    {
        ans[i][1]+=ans[i-1][1]+8*(i-2)+t[1];
        ans[i][2]+=ans[i-1][2]+8*(i-2)+t[2];
        ans[i][3]+=ans[i-1][3]+8*(i-2)+t[3];
        ans[i][4]+=ans[i-1][4]+8*(i-2)+t[4];
        answer+=ans[i][1]+ans[i][2]+ans[i][3]+ans[i][4];
        cout<<i<<" "<<answer<<endl;
        if(i==10)
        {
            cout<<i<<endl;
            char c;
            cin>>c;
        }
    }
    cout<<answer;
    return 0;
}
