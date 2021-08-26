///DARK PROGRAMMER


#include <iostream>

using namespace std;

struct ll
{
    ll *pre;
    int x;
    ll *nxt;
};

ll mom;

void add(ll* tmp,int y)
{
    ll* neww=new ll;
    neww->x=y;
    neww->pre=tmp;
    neww->nxt=tmp->nxt;
    if(neww->nxt!=NULL)
        (neww->nxt)->pre=neww;
    tmp->nxt=neww;
}
char a[1010][1010];
bool check(ll* tmp ,int i)
{
    while(tmp->nxt!=NULL)
        tmp=tmp->nxt;
    return(a[tmp->x][i]=='1');
}

int main()
{
    ll* tmp;
    mom.nxt=NULL;
    mom.pre=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
    {
        tmp=&mom;
        if(i==0)
        {
           add(tmp,0);
        }
        else
        {
            if(a[i][tmp->nxt->x]=='1')
                add(tmp,i);
            else if(check(tmp,i))
            {
                while(tmp->nxt!=NULL)
                    tmp=tmp->nxt;
                add(tmp,i);
            }
            else
            {
                while(a[tmp->nxt->x][i]=='1'&&tmp->nxt!=NULL)
                    tmp=tmp->nxt;

                add(tmp,i);
            }
        }
    }
    tmp=&mom;
    for(int i=0;i<n;i++)
    {
        cout<<tmp->nxt->x+1<<" ";
        tmp=tmp->nxt;
    }
    return 0;
}
