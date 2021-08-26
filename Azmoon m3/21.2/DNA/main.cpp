#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10687;
vector <int> s[(1<<13)];
int ans;
int jad[8][8];
bool solve(int x,int y)
{
    for(int i=0;i<6;i++)
    {
        jad[0][i]=s[x][i];
        jad[i][0]=s[y][i];
    }
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            jad[i][j]=6-jad[i-1][j]-jad[i][j-1]-jad[i-1][j-1];
            set <int> st;
            st.insert(jad[i-1][j]);
            st.insert(jad[i][j]);
            st.insert(jad[i][j-1]);
            st.insert(jad[i-1][j-1]);

            if(st.size()!=4||(jad[i][j]>3||jad[i][j]<0))
            {
                return 0;
            }
        }
    }
    if(jad[1][5]==1&&jad[4][1]==3&&jad[5][3]==3){
        for(int i=0;i<6;i++,cout<<"\n")
            for(int j=0;j<6;j++)
                cout<<jad[i][j]<<' ';
        cout<<endl;
        getchar();
        return 1;
    }
    else
        return 0;
}
main()
{
    for(int i=0;i<(1<<12);i++)
    {
        vector <int> t;
        int tmp=i;
        for(int j=0;j<6;j++)
        {
            t.push_back(tmp%4);
            tmp/=4;
        }
        for(int j=5;j>=0;j--)
            s[i].push_back(t[j]);
    }
    for(int i=0;i<(1<<12);i++)
    {
        for(int j=0;j<(1<<12);j++)
        {
            if(s[i][0]==s[j][0]&&s[j][1]==0&&s[i][2]==2)
            {
                ans+=solve(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
