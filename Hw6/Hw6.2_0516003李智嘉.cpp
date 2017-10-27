#include <iostream>
using namespace std;

int main()
{
	int t,n,max,num,temp,tmax;
	int a[1200],b[1200];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=1;
		}
		tmax=0;
		for(int i=n-1;i>=0;i--)
		{
			max=0;
			for(int j=i+1;j<n;j++)
				if(a[i]<=a[j]&&b[j]>max)
					max=b[j];
			b[i]+=max;
			if(b[i]>tmax)
				tmax=b[i];
		}
		cout<<tmax<<endl;
	}
	return 0;
}