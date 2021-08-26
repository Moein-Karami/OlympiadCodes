///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=60,inf=1e9;;
bool b[maxn][maxn],c[maxn][maxn];
int a[maxn][maxn];

main()
{
    int n,m,r,s;
    cin>>n>>m>>r>>s;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(j<1||j>m||i<1||i>n)
                a[i][j]=inf;
            else
                cin>>a[i][j];
        }
    }
    //for(int i=1;i<=n;i++)
    //{
      // for(int j=1;j<=m;j++)
       // {
        //    cout<<a[i][j]<<" ";
        //}cout<<endl;
    //}cout<<endl;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i!=j&&i!=-j)
            {
                b[r+i][s+j]=1;
                c[r+i][s+j]=1;
            }
        }
    }
    ///
    //for(int i=1;i<=n;i++)
    //{
        //for(int j=1;j<=m;j++)
        //{
            //if(b[i][j])
             //   cout<<"X";
           // else
          //     cout<<".";
        //}
      //  cout<<endl;
    //}
    //cout<<endl;
    ///
    b[r][s]=1;
    c[r][s]=1;
    ///
    //for(int i=1;i<=n;i++)
    //{
      //  for(int j=1;j<=m;j++)
        //{
          //  if(b[i][j])
            //   cout<<"X";
            //else
              //  cout<<".";
        //}
        //cout<<endl;
    //}
    //cout<<endl;
    ///
    bool z=1;
    int t;
    while(z)
    {
        z=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[i][j]&&(i!=r||j!=s))
                {
                    t=0;
                    for(int q=-1;q<=1;q++)
                    {
                        for(int w=-1;w<=1;w++)
                        {
                            if(q!=w&&q!=-w)
                            {
                                bool h=1;
                                if(!b[i+q][j+w])
                                {
                                    if(!c[i+q][j+w])
                                        t+=a[i+q][j+w];
                                }
                            }

                        }
                    }
                    if(t<=a[i][j])
                    {
                        z=1;
                        b[i][j]=0;
                        for(int q=-1;q<=1;q++)
                        {
                            for(int w=-1;w<=1;w++)
                            {
                                if(q!=w&&q!=-w)
                                {
                                    bool h=1;
                                    if(!b[i+q][j+w])
                                    {
                                        if(!c[i+q][j+w])
                                        {
                                            b[i+q][j+w]=1;
                                            c[i+q][j+w]=1;
                                        }
                                    }

                                }

                            }
                        }
                        ///
                        //for(int l=1;l<=n;l++)
                        //{
                          //  for(int k=1;k<=m;k++)
                            //    {
                              //      if(b[l][k])
                                //        cout<<"X";
                                  //  else
                                    //    cout<<".";
                                //}
                                //cout<<endl;
                            //}
                        //cout<<endl;
                        ///
                    }
                }
            }
        }

    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j])
                ans+=a[i][j];
    cout<<ans<<endl;
    b[r][s]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j])
                cout<<"X";
            else
                cout<<".";
        }cout<<endl;
    }
    //for(int i=1;i<=n;i++)
    //{
      //  for(int j=1;j<=m;j++)
        //{
          //  cout<<b[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    return 0;
}
