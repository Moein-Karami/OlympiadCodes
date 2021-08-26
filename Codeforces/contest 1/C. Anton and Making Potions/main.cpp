#include <iostream>

using namespace std;
int spel1z[100000],spel1p[100000];
int spel2t[100000],spel2p[100000];
int ps[100000];
int main()
{
    int tmp=0,tmp2=0,cnt=0,cnt2=0,mini1=1000000,mini2=1000000,mini3=1000000;
    //cin ha
    int majoon,spel1,spel2;
    cin>>majoon>>spel1>>spel2;

    int adi,pool;
    cin>>adi>>pool;

    for(int i=1;i<=spel1;i++)
        cin>>spel1z[i];
    for(int i=1;i<=spel1;i++)
        cin>>spel1p[i];

    for(int i=1;i<=spel2;i++)
        cin>>spel2t[i];
    for(int i=1;i<=spel2;i++)
        cin>>spel2p[i];
    //payan
    for(int i=1;i<=spel1;i++)
    {
        if(spel1p[i]<pool)
        {
            ps[i]=majoon*spel1z[i];
        }
    }

    return 0;
}
