#include <iostream>
#include <algorithm>
using namespace std;

int yq=1;

int Partition(int *a,int p,int r)
{
	int i=p-1;
	for(int j=p;j<r;j++)
		if(a[j]<=a[r])
		{
			i++;
			swap(a[i],a[j]);
		}
	swap(a[i+1],a[r]);
	return i+1;
}

void Quicksort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=Partition(a,p,r);
		if(q!=p&&q!=r)
			yq=0;
		Quicksort(a,p,q-1);
		Quicksort(a,q+1,r);
	}
}

int main()
{
	int t,n,*a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		yq=1;
		a=new int[n+2];
		for(int i=0;i<n;i++)
			cin>>a[i];
		Quicksort(a,0,n-1);
		if(yq)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		delete []a;
	}
	return 0;
}