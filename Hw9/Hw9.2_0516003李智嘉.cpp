#include <iostream>
using namespace std;

int done[10005]={0},value[10005],Max=0,count=0;

typedef struct l
{
	int idx;
	struct l *next;
}H;
H *peo[30005];

void insert(H *now,int num)
{
	while(now->next!=NULL)
		now=now->next;
	now->next=new H;
	now->idx=num;
}

void run(H *now)
{
	while(now->next!=NULL)
	{
		if(!done[now->idx])
		{
			done[now->idx]=1;
			count+=value[now->idx];
			run(peo[now->idx]);
			count-=value[now->idx];
		}
		now=now->next;
	}
	if(Max<count)
		Max=count;
}

int main()
{
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>value[i];
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		if(peo[a]==NULL)
			peo[a]=new H;
		if(peo[b]==NULL)
			peo[b]=new H;
		insert(peo[a],b);
		insert(peo[b],a);
	}
	done[1]=1;
	count+=value[1];
	run(peo[1]);
	cout<<Max<<endl;
	return 0;
}