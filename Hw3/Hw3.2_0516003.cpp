#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	long long int s[1000000],t,n,k,p,q,r,total,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>p>>q>>r;
		memset(s,0,sizeof(long long int)*1000000);
		for(i=1;i<=n;i++)
			s[(i*i*p+i*q+r)%1000000]++;
		total=0;
		for(i=0;i<1000000;i++)
		{
			total+=s[i];
			if(total>=k)
				break;
		}
		cout<<i<<endl;
	}
	return 0;
}