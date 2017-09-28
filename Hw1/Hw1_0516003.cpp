#include <iostream>
using namespace std;

int main()
{
	unsigned long long int b[1000][2][2]={0},i,j,k,l,ini[2],t,n,now,x,y;
	b[0][0][0]=1;
	b[0][0][1]=1;
	b[0][1][0]=1;
	b[0][1][1]=0;
	for(i=1;i<1000;i++)
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
				for(l=0;l<2;l++)
					b[i][j][l]+=b[i-1][j][k]*b[i-1][k][l];
			for(l=0;l<2;l++)
				b[i][j][l]%=29989;
		}
	cin>>t;
	while(t--)
	{
		cin>>n;
		now=0;
		ini[0]=1;ini[1]=0;
		while(n!=1)
		{
			if(n%2)
			{
				x=(b[now][0][0]*ini[0]+b[now][0][1]*ini[1])%29989;
				y=(b[now][1][0]*ini[0]+b[now][1][1]*ini[1])%29989;
				ini[0]=x; ini[1]=y;
			}
			now++;
			n/=2;
		}
		cout<<(b[now][1][0]*ini[0]+b[now][1][1]*ini[1])%29989<<endl;
	}
	return 0;
}