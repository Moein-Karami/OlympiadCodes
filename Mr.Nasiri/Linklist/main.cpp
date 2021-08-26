///DARK PROGRAMMER


#include <iostream>

using namespace std;
struct ll
{
    ll *pre;
    int x;
    ll *nxt;
    void get(ll* tnxt , ll* tpre)
    {
        cin>>x;
        this->nxt=tnxt;
        this->pre=tpre;
    }
};

ll mom;


void add(ll* tmp )
{
    ll *neww;
    neww->get(tmp , tmp->nxt);
    if(tmp->nxt!=NULL)
        (tmp->nxt)->pre=neww;
    tmp=neww;
}
void rem(ll* tmp)
{
    (tmp->pre)->nxt=tmp->nxt;
    if(tmp->nxt!=NULL)
    {
        (tmp->nxt)->pre=tmp->pre;
    }
}
int n=0;
int main()
{
    mom.nxt=NULL;
    mom.pre=NULL;
    ll *tmp=&mom;
    int r=1;
    int cnt;
    while(r)
    {
        tmp=&mom;
        cin>>r;
        if(r==1)
        {
            n++;
            cin>>cnt;
            if(cnt>n)
            {
                cout<<"INVALID"<<endl;
            }
            else
            {
                for(int i=1;i<cnt;i++)
                    tmp=tmp->nxt;
                add(tmp);
            }
        }
        if(r==2)
        {
            cin>>cnt;
            if(cnt>n)
                cout<<"INVALID"<<endl;
            else
            {
                n--;
                for(int i=1;i<=cnt;i++)
                    tmp=tmp->nxt;
                rem(tmp);
            }
        }
        if(r==3)
        {
            cin>>cnt;
            if(cnt>n)
                cout<<"INVALID"<<endl;
            else
            {
              for(int i=1;i<=cnt;i++)
                    tmp=tmp->nxt;
                cout<<(*tmp).x<<endl;
            }
        }
    }
    return 0;
}
