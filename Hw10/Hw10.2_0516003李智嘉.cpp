#include <iostream>
#include <cstring>
#include <list>
#include <vector>
using namespace std;

int value[10005],visit[10005],low[10005],t,n,m;
list<int>pt[10005];
vector<int> stack,clstnum;
bool instack[10005],done[10005];
int findcount;

void clust(int id)
{
	visit[id]=low[id]=++t;
	stack.push_back(id);
	instack[id]=true;
	for(list<int>::iterator it=pt[id].begin();it!=pt[id].end();it++)
	{
		if(!visit[*it])
			clust(*it);
		if(instack[*it])
			low[id]=min(low[id],low[*it]);
	}
	if(visit[id]==low[id])
	{
		int j;
		clstnum.push_back(id);
		do
		{
			j=stack.back();
			stack.pop_back();
			instack[j]=false;
			value[id]++;
		}while(id!=j);
	}
}

void go(int i)
{
	if(done[i]||findcount==n)
		return;
	done[i]=true;
	findcount++;
	for(list<int>::iterator it=pt[i].begin();it!=pt[i].end();it++)
		go(*it);
}

int main()
{
	int times,a,b;
	cin>>times;
	while(times--)
	{
		stack.clear();
		clstnum.clear();
		t=0;
		cin>>n>>m;
		memset(value,0,sizeof(int)*(n+5));
		memset(visit,0,sizeof(int)*(n+5));
		memset(low,0,sizeof(int)*(n+5));
		memset(instack,0,sizeof(bool)*(n+5));
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			pt[a].push_back(b);
		}
		for(int i=1;i<=n;i++)
			if(!visit[i])
				clust(i);
		int result=0;
		for(vector<int>::iterator it=clstnum.begin();it!=clstnum.end();it++)
		{
			findcount=0;
			memset(done,0,sizeof(bool)*(n+5));
			go(*it);
			if(findcount==n)
			{
				result=value[*it];
				break;
			}
		}
		cout<<result<<endl;

		for(int i=1;i<=n;i++)
			pt[i].clear();
	}
	return 0;
}