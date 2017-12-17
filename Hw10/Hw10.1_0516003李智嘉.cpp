#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

typedef struct l
{
	int p1,p2,w,lid;
	friend bool operator>(const struct l &a,const struct l &b){return a.w>b.w;}
}line;

typedef struct s
{
	int a,b;
	friend bool operator<(const struct s &i,const struct s &j)
	{return i.a<j.a?true:(i.a>j.a?false:(i.b<j.b?true:false));}
}se;

int p[100005];
int find(int x)
{
	return x==p[x]?x:(p[x]=find(p[x]));
}
void unio(int x,int y)
{
	p[find(x)]=find(y);
}


int main()
{
	priority_queue<line,vector<line>,greater<line> > pq;
	int n,m,now,c;
	bool liExist[100005]={0};
	vector<se> update;
	se tmp;
	line temp;
	se temp2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&temp.p1,&temp.p2,&temp.w);
		temp.lid=i;
		p[i]=i;
		pq.push(temp);
	}
	now=pq.top().w;
	c=0;
	while(!pq.empty())
	{
		temp=pq.top();
		pq.pop();
		if(now!=temp.w)
			while(!update.empty())
			{
				tmp=update.back();
				update.pop_back();
				unio(tmp.a,tmp.b);
			}
		now=temp.w;
		if(find(temp.p1)!=find(temp.p2))
		{
			liExist[temp.lid]=true;
			if(temp.p1>temp.p2)
			{
				temp2.a=temp.p2;
				temp2.b=temp.p1;
			}
			else
			{
				temp2.a=temp.p1;
				temp2.b=temp.p2;
			}
			update.push_back(temp2);
			c++;
		}
	}
	for(int i=0;i<m;i++)
		if(liExist[i])
			cout<<"at least one"<<endl;
		else
			cout<<"none"<<endl;
	return 0;
}