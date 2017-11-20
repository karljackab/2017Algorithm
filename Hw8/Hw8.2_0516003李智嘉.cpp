#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t,n,i,j,k;
	bool a[105][2000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		int itn=1;
		memset(a,0,105*2000*sizeof(bool));
		while(itn<=n)
		{
			cin>>i>>j>>k;
			if(itn==1)
			{
				a[itn][i]=true; a[itn][j]=true; a[itn][k]=true;
			}
			if(itn-1)
				for(int l=0;l<=1024;l++)
					if(a[itn-1][l])
					{
						a[itn][l^i]=true; a[itn][l^j]=true; a[itn][l^k]=true;
					}
			itn++;
		}
		for(i=1024;i>=0&&!a[n][i];i--);
		cout<<i<<endl;
	}
	return 0;
}