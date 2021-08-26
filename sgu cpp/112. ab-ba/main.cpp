///Chefer


#include <bits/stdc++.h>

using namespace std;
int bg[2][1000];
int cnt[2];
void fix(int x)
{
    for(int i=0;i<=cnt[x];i++)
    {
        if(bg[x][cnt[x]]>=10)
        {
            bg[x][cnt[x]+1]+=bg[x][cnt[x]]/10;
            bg[x][cnt[x]]%=10;
            cnt[x]++;
        }
        bg[x][i+1]+=bg[x][i]/10;
        bg[x][i]%=10;
    }
}
void t(int x,int y)
{
    for(int i=0;i<=cnt[x];i++)
        bg[x][i]*=y;
    fix(x);
}
main()
{
    int a,b;
    cin>>a>>b;
    bg[0][0]=1;
    bg[1][0]=1;
    for(int i=1;i<=b;i++)
        t(0,a);
    for(int i=1;i<=a;i++)
        t(1,b);
    if(cnt[1]>cnt[0])
    {
        cout<<"-";
        swap(bg[0],bg[1]);
        swap(cnt[0],cnt[1]);
    }
    else
    {
        for(int i=cnt[0];i>=0;i--)
        {
            if(bg[0][i]!=bg[1][i])
            {
                if(bg[0][i]<bg[1][i])
                {
                    cout<<"-";
                    swap(bg[0],bg[1]);
                }
                i=-1;
            }
        }
    }
    for(int i=0;i<=cnt[0];i++)
    {
        bg[0][i]-=bg[1][i];
        while(bg[0][i]<0)
        {
            bg[0][i]+=10;
            bg[0][i+1]--;
        }
    }
    while(!bg[0][cnt[0]]&&cnt[0])
        cnt[0]--;
    for(int i=cnt[0];i>=0;i--)
        cout<<bg[0][i];
    return 0;
}
