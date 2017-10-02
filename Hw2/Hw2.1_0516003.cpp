#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int *a,int i,int n)
{
	int l=i*2,r=i*2+1,largest=i;
	if(l<=n&&a[l]>a[i])
		largest=l;
	if(r<=n&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		maxHeapify(a,largest,n);
	}
}

void buildMaxHeap(int *a,int n)
{
	for(int i=n/2;i>0;i--)
		maxHeapify(a,i,n);
}

void HeapSort(int *a,int n,int *out)
{
	buildMaxHeap(a,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=n;i>=2;i--)
	{
		out[i]=a[1];
		swap(a[1],a[i]);
		n--;
		maxHeapify(a,1,n);
	}
	out[1]=a[1];
}

int main()
{
	int n,*a,*b;
	cin>>n;
	a=new int[n+5];
	b=new int[n+5];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	HeapSort(a,n,b);
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}