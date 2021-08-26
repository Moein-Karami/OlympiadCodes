///Chefer

#include<bits/stdc++.h>
#define int long long int
#define f first
#define s second
#define rand() rand()*rand()

using namespace std;

typedef pair<int,int> pii;
const int maxn=1e5+5;
int a[maxn];
pii tmp[maxn];
int lazy[maxn];
int add[maxn];
int n;
int sq;
int po=1;
map<int,int> mp;
inline void fix_a(int g)
{
	for(int i=sq*g;i<min(n,sq*(g+1));i++)
	{
		if(lazy[g])
			a[tmp[i].s]=lazy[g];
		else
			a[tmp[i].s]=tmp[i].f;
		a[tmp[i].s]+=add[g];
	}
	lazy[g]=0;
	add[g]=0;
}
inline void fix_g(int g)
{
	for(int i=sq*g;i<min(n,(g+1)*sq);i++)
	{
		tmp[i].f=a[i];
		tmp[i].s=i;
	}
	sort(tmp+g*sq,tmp+min((g+1)*sq,n));
}
inline bool found(int g,int x)
{
	x-=add[g];
	if(lazy[g])
		return (lazy[g]==x);
	int l=g*sq,r=min((g+1)*sq,n);
	int mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(tmp[mid].f<=x)
			l=mid;
		else
			r=mid;
	}
	return (tmp[l].f==x);
}
main()
{
	ios_base::sync_with_stdio(false);
	mp[po]=1;
	for(int i=1;i<=7;i++)
	{
		po*=42;
		mp[po]=1;
	}
	int Q;
	cin>>n>>Q;
	sq=sqrt(n)+1;
	//cerr<<"FUCK3"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tmp[i].f=a[i];
		tmp[i].s=i;
	}
	//cerr<<"FUCK2"<<endl;
	for(int i=0;i<sq;i++)
		if(i*sq<n)
			sort(tmp+i*sq,tmp+min((i+1)*sq,n));
	//cerr<<"FUCK1"<<endl;
	int tp,l,r,x,g,gr;
	bool f;
	for(int T=1;T<=Q;T++)
	{
		cin>>tp>>l;
		l--;
		g=l/sq;
		if(tp==1)
		{
			fix_a(g);
			fix_g(g);
			cout<<a[l]<<"\n";
		}
		else if(tp==2)
		{
			cin>>r>>x;
			r--;
			gr=r/sq;
			for(int i=g+1;i<gr;i++)
				add[i]=0,lazy[i]=x;
			fix_a(g);
			fix_a(gr);
			for(int i=l;i<=min(r,(g+1)*sq-1);i++)
				a[i]=x;
			for(int i=r;i>=max(l,gr*sq);i--)
				a[i]=x;
			fix_g(g);
			fix_g(gr);
		}
		else
		{
			cin>>r>>x;
			r--;
			gr=r/sq;
			fix_a(g);
			fix_a(gr);
			for(int k=1;k<=5*maxn;k++)
			{
				f=0;
				for(int i=l;i<=min(r,(g+1)*sq-1);i++)
				{
					if(mp[a[i]+k*x])
					{
						f=1;
						break;
					}
				}
				if(f)
					continue;
				for(int i=r;i>=max(l,sq*gr);i--)
				{
					if(mp[a[i]+k*x])
					{
						f=1;
						break;
					}
				}
				if(f)
					continue;
				for(int i=g+1;i<gr;i++)
				{
					po=1;
					for(int i=1;i<=8;i++)
					{
						if(found(i,po-k*x))
							f=1;
						if(f)
							break;
						po*=42;
					}
					if(f)
						break;
				}
				if(f)
					continue;
				for(int i=l;i<=min(r,(g+1)*sq-1);i++)
					a[i]+=k*x;
				for(int i=r;i>=max(l,gr*sq);i--)
					a[i]+=k*x;
				for(int i=g+1;i<gr;i++)
					add[i]+=k*x;
				fix_g(g);
				fix_g(gr);
				break;
			}
		}
	}
	return 0;
}
