#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector <int> tl,tr;
int l[20],r[20];
int ansl,ansr;
int solvel(int i,int j,bool b)
{
    if(i==tl.size()+1)
        return 1;
    int ans=0;
    if(b==0)
    {
        for(int q=0;q<=9;q++)
        {
            if(q==3)
            {
                if(j!=1)
                    ans+=solvel(i+1,3,0);
            }
            else
                ans+=solvel(i+1,q,0);
        }
    }
    else
    {
        if(j==1)
        {
            for(int q=0;q<l[i];q++)
            {
                if(q!=3)
                    ans+=solvel(i+1,q,0);
            }
            if(l[i]!=3)
                ans+=solvel(i+1,l[i],1);
        }
        else
        {
            for(int q=0;q<l[i];q++)
            {
                ans+=solvel(i+1,q,0);
            }
            ans+=solvel(i+1,l[i],1);
        }
    }
    return ans;
}
int solver(int i,int j,bool b)
{
    if(i==tr.size()+1)
        return 1;
    int ans=0;
    if(b==0)
    {
        for(int q=0;q<=9;q++)
        {
            if(q==3)
            {
                if(j!=1)
                    ans+=solver(i+1,3,0);
            }
            else
                ans+=solver(i+1,q,0);
        }
    }
    else
    {
        if(j==1)
        {
            for(int q=0;q<r[i];q++)
            {
                if(q!=3)
                    ans+=solver(i+1,q,0);
            }
            if(r[i]!=3)
                ans+=solver(i+1,r[i],1);
        }
        else
        {
            for(int q=0;q<r[i];q++)
            {
                ans+=solver(i+1,q,0);
            }
            ans+=solver(i+1,r[i],1);
        }
    }
    return ans;
}
main()
{
    int L,R;
    cin>>L>>R;
    while(L)
    {
        tl.push_back(L%10);
        L/=10;
    }
    while(R)
    {
        tr.push_back(R%10);
        R/=10;
    }
    for(int i=tl.size();i>=1;i--)
        l[i]=tl[tl.size()-i];
    for(int i=tr.size();i>=1;i--)
        r[i]=tr[tr.size()-i];
    for(int i=0;i<l[1];i++)
    {
        ansl+=solvel(2,i,0);
    }
    ansl+=solvel(2,l[1],1);
    for(int i=0;i<r[1];i++)
    {
        ansr+=solver(2,i,0);
    }
    ansr+=solver(2,r[1],1);
    cout<<ansr-ansl;
    return 0;
}
