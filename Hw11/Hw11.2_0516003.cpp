#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 2147483647

void delete2D(int n,int **p)
{
	for(int i=0;i<n;i++)
	{
		delete []p[i];
	}
	delete []p;
}

int BFS(int n,int **limit,int *path,int s,int t,int **aug)
{
	bool *visit;
	int nowstart,*minPath;
	visit=new bool[n];
	minPath=new int[n];
	for(int i=0;i<n;i++)
	{
		visit[i]=false;
		minPath[i]=MAX;
	}
	queue<int> q;
	visit[s]=true;
	path[s]=s;
	minPath[s]=MAX;
	q.push(s);
	while(!q.empty())
	{
		nowstart=q.front();	q.pop();
		for(int i=0;i<n;i++)
			if(!visit[i]&&aug[nowstart][i]>0)
			{
				visit[i]=true;
				path[i]=nowstart;
				minPath[i]=min(minPath[nowstart],aug[nowstart][i]);
				q.push(i);
				if(i==t)
				{
					int result=minPath[t];
					delete visit; delete minPath;
					return result;
				}
			}
	}
	delete visit; delete minPath;
	return 0;
}

int MaxFlow(int n,int **limit,int s,int t)
{
	int **flow,minCost,*path,totalFlow=0,**aug;
	flow=new int*[n];
	for(int i=0;i<n;i++)
	{
		flow[i]=new int[n];
		memset(flow[i],0,sizeof(int)*n);
	}
	aug=new int*[n];
	for(int i=0;i<n;i++)
	{
		aug[i]=new int[n];
		memcpy(aug[i],limit[i],sizeof(int)*n);
	}
	path=new int[n];
	memset(path,0,sizeof(int)*n);
	
	while(minCost=BFS(n,limit,path,s,t,aug))
	{
		totalFlow+=minCost;
		for(int i=path[t],j=t;i!=j;i=path[j=i])
		{
			flow[i][j]+=minCost;
			flow[j][i]=-flow[i][j];
			aug[i][j]=limit[i][j]-flow[i][j];
			aug[j][i]=limit[j][i]-flow[j][i];
		}
	}
	delete2D(n,flow);
	delete2D(n,aug);
	delete path;
	return totalFlow;
}


int main()
{
	int t,fam,tab,family[30],table[30],n,total;
	int **limit;
	cin>>t;
	while(t--)
	{
		cin>>fam>>tab;
		n=fam+tab+2;
		total=0;
		limit=new int*[n];
		for(int i=0;i<n;i++)
		{
			limit[i]=new int[n];
			memset(limit[i],0,sizeof(int)*n);
		}

		for(int i=0;i<fam;i++)
		{
			cin>>family[i];
			limit[0][i+1]=family[i];
			total+=family[i];
		}
		for(int i=0;i<tab;i++)
		{
			cin>>table[i];
			limit[i+fam+1][n-1]=table[i];
		}
		for(int i=1;i<=fam;i++)
			for(int j=fam+1;j<n-1;j++)
				limit[i][j]=1;
		int a=MaxFlow(n,limit,0,n-1);
		if(a==total)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		delete2D(n,limit);
	}
	return 0;
}