#include <iostream>
#include <algorithm>
using namespace std;
long long int ai[3],bi[3],remain,result;

long long int calc(long long int x,long long int t)
{
	if(!t)
		return ai[0]*x*x+ai[1]*x+ai[2];
	return bi[0]*x*x+bi[1]*x+bi[2];
}

long long int search(long long int l,long long int r,long long int type,long long int tar)
{
	long long int now=l,step=(r-l)/2;
	while(step)
	{
		if(now+step>=r)
			step/=2;
		else if(calc(now+step,type)<=tar)
			now+=step;
		else
			step/=2;
	}
	if(calc(now,type)>tar)
		return now;
	else
		return now+1;
}

void go(long long int ah,long long int at,long long int bh,long long int bt)
{
	long long int a,b,am,bm,i,c=0;
	while(1)
	{
		a=(ah+at)/2,b=(bh+bt)/2,am=calc(a,0),bm=calc(b,1),i;
		if(am<bm)
			b=search(bh,bt,1,am);
		else
			a=search(ah,at,0,bm);
		if(ah==at||bh==bt)
			break;
		i=a-ah+b-bh;
		if(i<=remain)
		{
			remain-=i;
			result=min(calc(a,0),calc(b,1));
			if(remain==1)
			{
				c=1;
				break;
			}
			else if(!remain)
			{
				result=max(calc(a-1,0),calc(b-1,1));
				c=1;
				break;
			}
			if(remain==2&&a==ah&&b==bh)
			{
				result=max(calc(a,0),calc(b,1));
				c=1;
				break;
			}
			ah=a;
			bh=b;
		}
		else
		{
			at=a;
			bt=b;
		}
	}
	if(!c&&remain!=1&&remain!=0)
	{
		if(ah==at)
			result=calc(bh+remain-1,1);
		else
			result=calc(ah+remain-1,0);
	}
}

int main()
{
	long long int t,i,j,k,n;
	cin>>t;
	while(t--)
	{
		for(i=0;i<3;i++)
			cin>>ai[i];
		for(i=0;i<3;i++)
			cin>>bi[i];
		result=0;
		cin>>n;
		remain=n;
		go(0,n,0,n);
		cout<<result<<endl;
	}
	return 0;
}