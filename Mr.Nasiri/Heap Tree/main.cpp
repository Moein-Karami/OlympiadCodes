///DARK PROGRAMMER


#include <iostream>
#include <vector>
using namespace std;
vector<int> heap;
int n;

void bet(int cnt)
{
    if(heap[cnt]>heap[cnt/2])
    {
        swap(heap[cnt],heap[cnt/2]);
        cnt/=2;
        bet(cnt);
    }
    int q;
    q=cnt*2;
    if(heap[cnt*2]<heap[cnt*2+1])
        q++;

    if(heap[cnt]<heap[q])
    {
        swap(heap[cnt],heap[q]);
        bet(q);

    }
}
int main()
{
    heap.push_back(1e9+7);
    int r=1;
    int x,cnt;
    while(r)
    {
        cin>>r;
        if(r==1)
        {
            cin>>x;
            heap.push_back(x);
            n++;
            bet(n);
        }
        if(r==2)
        {
            cin>>cnt;
            swap(heap[cnt],heap[n]);
            heap.pop_back();
            n--;
            bet(cnt);
        }
        if(r==3)
        {
            for(int i=1;i<=n;i++)
                cout<<heap[i]<<" ";
                cout<<endl;
        }
    }

    return 0;
}
