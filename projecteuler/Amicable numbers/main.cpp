///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
int ans[10010];
int main()
{
    for(int i=2;i<=10000;i++)
    {
        int tmp=i;
        ans[tmp]++;
        for(int j=2;j<i;j++)
        {
            if(tmp%j==0)
            {
                ans[i]+=j;
            }
        }
    }
    cout<<ans[220]<<" "<<ans[284]<<endl;;
    int answer=0;
    for(int i=2;i<=10000;i++)
    {
        for(int j=2;j<=10000;j++)
        {
            if(i!=j&&ans[i]==j&&ans[j]==i)
            {
                answer+=i;
                j=100001;
            }
        }
    }
    cout<<answer;
    return 0;
}
