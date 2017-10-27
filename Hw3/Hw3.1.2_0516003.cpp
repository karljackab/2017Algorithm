#include <iostream>
#include <algorithm>
using namespace std;
long long int ai[3],bi[3],remain,result;

long long int calc(long long int x,long long int t)
{
	if(!t)
		return ai[0]*x*x+ai[1]*x+ai[2]; //t=0
	return bi[0]*x*x+bi[1]*x+bi[2];
}

void go(long long int al,long long int ar,long long int bl,long long int br)
{
	long long int c[4],aimid,bimid;
	double amid,bmid;
	while(ar-al>1||br-bl>1)
	{
		aimid=(al+ar)/2;
		bimid=(bl+br)/2;
		if((al+ar)%2)
			amid=(calc(aimid,0)+calc(aimid+1,0))/2;
		else
			amid=calc(aimid,0);
		if((bl+br)%2)
			bmid=(calc(bimid,1)+calc(bimid+1,1))/2;
		else
			bmid=calc(bimid,1);
		if(amid==bmid)
		{
			result=amid;
			return;
		}
		if(amid>bmid)
		{
			ar=aimid;
			if((bl+br)%2)
				bl=bimid+1;
			else
				bl=bimid;
		}
		else
		{
			if((al+ar)%2)
				al=aimid+1;
			else
				al=aimid;
			br=bimid;
		}
	}
	int i,j;
	for(i=al,j=0;i<=ar;i++,j++)
		c[j]=calc(i,0);
	for(i=bl;i<=br;i++,j++)
		c[j]=calc(i,1);
	sort(c,c+j);
	result=c[(j-1)/2];
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
		cin>>n;
		go(0,n-1,0,n-1);
		cout<<result<<endl;
	}
	return 0;
}