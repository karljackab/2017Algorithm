#include <iostream>
using namespace std;

int main()
{
	int t,n,m,count;
	char temp;
	unsigned long long int now;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		count=0;now=0;
		while(n--)
		{
			cin>>temp;
			now=now*10+temp-'0';
			now%=m;
			if(!now)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}