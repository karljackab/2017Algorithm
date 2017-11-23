#include <iostream>
using namespace std;

int done[30005]={0},count=0,donec=0,n;

typedef struct l
{
	int idx;
	struct l *next,*last;
}H;
H *peo[30005];

void insert(H *now,int num)
{
	now->last->next=new H;
	now->last=now->last->next;
	now->last->idx=num;
	now->last->next=NULL;
}

void search(H *now)
{
	while(now!=NULL)
	{
		if(donec==n)
			return;
		if(!done[now->idx])
		{
			done[now->idx]=1;
			donec++;
			count++;
			search(peo[now->idx]);
		}
		now=now->next;
	}
}

int main()
{
	int m,a,b,max=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(peo[a]==NULL)
		{
			peo[a]=new H;
			peo[a]->idx=a;
			peo[a]->last=peo[a];
		}
		if(peo[b]==NULL)
		{
			peo[b]=new H;
			peo[b]->idx=b;
			peo[b]->last=peo[b];
		}
		insert(peo[a],b);
		insert(peo[b],a);
	}
	for(int i=1;donec!=n&&i<=n;i++)
	{
		count=0;
		if(done[i])
		{
			donec++;
			continue;
		}
		search(peo[i]);
		if(max<count)
			max=count;
	}
	cout<<max<<endl;
	return 0;
}