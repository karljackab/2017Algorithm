#include <iostream>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 2147483647

int n,m,q;

struct line
{
	int t,w;
};
struct node
{
	int id,w;
	bool operator>(const node &b) const{return w>b.w;}
};

void Bellman_Ford(list<line> *point,int *ptweight,int first)
{
	for(int i=1;i<=n;i++)
		ptweight[i]=MAX;
	int now;
	queue<int> q;
	ptweight[first]=0;
	q.push(first);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(list<line>::iterator pit=point[now].begin();pit!=point[now].end();pit++)
			if(ptweight[pit->t]>ptweight[now]+pit->w)
			{
				ptweight[pit->t]=ptweight[now]+pit->w;
				q.push(pit->t);
			}
	}
	return;
}

void Dijkstra(list<line> *point,int *ptweight,int **mindis)
{
	priority_queue<node,vector<node>,greater<node> > q;
	node *nd,temp;
	nd=new node[n+1];
	for(int now=1;now<=n;now++)
	{
		for(int j=1;j<=n;j++)
		{
			nd[j].id=j;
			nd[j].w=MAX;
		}
		nd[now].w=0;
		mindis[now][now]=0;
		q.push(nd[now]);
		while(!q.empty())
		{
			temp=q.top();
			q.pop();
			for(list<line>::iterator it=point[temp.id].begin();it!=point[temp.id].end();it++)
				if(nd[it->t].w>nd[temp.id].w+it->w)
				{
					nd[it->t].w=nd[temp.id].w+it->w;
					mindis[now][it->t]=nd[it->t].w-ptweight[now]+ptweight[it->t];
					q.push(nd[it->t]);
				}
		}
	}
	return;
}

int main()
{
	int i,j,k;
	int *ptweight;
	int **mindis;
	line temp;
	list<line> *point;

	cin>>n>>m>>q;
	point=new list<line>[n+1];
	ptweight=new int[n+1];
	mindis=new int*[n+1];
	for(int i=1;i<=n;i++)
	{
		mindis[i]=new int[n+1];
		for(int j=1;j<=n;j++)
			mindis[i][j]=MAX;
	}

	for(i=0;i<m;i++)
	{
		cin>>j>>temp.t>>temp.w;
		point[j].push_back(temp);
	}
	for(i=1;i<=n;i++)
	{
		temp.t=i;
		temp.w=0;
		point[0].push_back(temp);
	}
	Bellman_Ford(point,ptweight,0);
	for(int i=1;i<=n;i++)
		for(list<line>::iterator it=point[i].begin();it!=point[i].end();it++)
			it->w=it->w+ptweight[i]-ptweight[it->t];
	Dijkstra(point,ptweight,mindis);
	for(int i=0;i<q;i++)
	{
		cin>>j>>k;
		if(mindis[j][k]!=MAX)
			cout<<mindis[j][k]<<endl;
		else
			cout<<"no path"<<endl;
	}
	return 0;
}