#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int a[305][305];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=n-2;i>=0;i--)
		a[i][n-1]+=a[i+1][n-1];
	for(int i=n-2;i>=0;i--)
		a[n-1][i]+=a[n-1][i+1];
	for(int i=n-2;i>=0;i--)
		for(int j=n-2;j>=0;j--)
			a[i][j]+=max(a[i][j+1],a[i+1][j]);
	cout<<a[0][0]<<endl;
	return 0;
}