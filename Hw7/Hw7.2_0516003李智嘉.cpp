#include <iostream>
#include <algorithm>
using namespace std;

typedef struct 
{
	long long int t,s;
	int idx;
	double m;
}node;

bool cmp(node a,node b)
{
	return a.m>b.m;
}

int main()
{
	int m,n;
	long long int height,bot,tot,time;
	node tk[100010];
	cin>>m;
	while(m--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>tk[i].t;
		time=0;
		for(int i=1;i<=n;i++)
		{
			cin>>tk[i].s;
			tk[i].idx=i;
			time+=tk[i].s;
			tk[i].m=double(tk[i].s)/double(tk[i].t);
		}
		sort(tk+1,tk+n+1,cmp);
		height=0;bot=0;tot=0;
		for(int i=1;i<=n;i++)
		{
			tot+=tk[i].t;
			height+=tk[i].s;
			bot+=tk[i].t*height;
		}
		tot*=time;
		cout<<tot-bot<<endl;
		for(int i=1;i<=n;i++)
			cout<<tk[i].idx<<" ";
		cout<<endl;
	}
	return 0;
}