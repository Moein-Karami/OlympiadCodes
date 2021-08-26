///Chefer


#include <bits/stdc++.h>

using namespace std;
int bg[4][1010];
int cnt[4];
int x[1010];
int tmp[1010];
bool check()
{
    if(cnt[0]!=cnt[2])
        return 1;
    for(int i=1;i<=cnt[0];i++)
        if(bg[0][i]!=bg[2][i])
            return 1;
    if(bg[0][0]+1==bg[2][0])
        return 0;
    return 1;
}
void fix(int h)
{
    for(int i=0;i<=cnt[h];i++)
    {
        if(bg[h][cnt[h]]>=10)
        {
            bg[h][cnt[h]+1]+=bg[h][cnt[h]]/10;
            bg[h][cnt[h]]%=10;
            cnt[h]++;
        }
        bg[h][i+1]+=bg[h][i]/10;
        bg[h][i]%=10;
    }
}
main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        x[i]=s[s.size()-i-1]-'0';
    bg[0][0]=1;
    bg[2][1000]=1;
    cnt[2]=1000;
    int cntx=s.size()-1;
    while(check())
    {
        fill(bg[1],bg[1]+1001,0);
        for(int i=0;i<=cnt[2];i++)
            bg[1][i]=bg[0][i]+bg[2][i];
        cnt[1]=cnt[2];
        fix(1);
        for(int i=cnt[1];i>=0;i--)
        {
            if(i>0)
                bg[1][i-1]+=bg[1][i]%2;
            bg[1][i]/=2;
        }
        if(!bg[1][cnt[1]])
            cnt[1]--;
        if(cnt[1]*2>cntx)
        {
            cnt[2]=cnt[1];
            for(int i=0;i<=cnt[2];i++)
                bg[2][i]=bg[1][i];
        }
        else if(cnt[1]*2+15<cntx)
        {
            cnt[0]=cnt[1];
            for(int i=0;i<=cnt[0];i++)
                bg[0][i]=bg[1][i];
        }
        fill(tmp,tmp+1002,0);


    }
    return 0;
}
