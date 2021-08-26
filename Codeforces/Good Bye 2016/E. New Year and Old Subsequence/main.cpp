#include <iostream>

using namespace std;
int sefr[300000],doo[300000],yek[300000],haft[300000],shesh[300000];
int main()
{
    int n;
    cin>>n;
    string s;
    int q;
    cin>>q;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            yek[i]++;
        if(s[i]=='2')
            doo[i]++;
        if(s[i]=='0')
            sefr[i]++;
        if(s[i]=='7')
            haft[i]++;
        if(s[i]=='6')
            shesh[i]++;
        if(i>=1)
        {
        yek[i]+=yek[i-1];
        doo[i]+=doo[i-1];
        sefr[i]+=sefr[i-1];
        haft[i]+=haft[i-1];
        shesh[i]+=shesh[i-1];
        }
    }
    int l,r;
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        if(haft[r-1]-haft[l-2]<=0||yek[r-1]-yek[l-2]<=0||doo[r-1]-doo[l-2]<=0||sefr[r-1]-sefr[l-2]<=0)
        {
            cout<<-1;
            return 0;
        }
    }
    return 0;
}
