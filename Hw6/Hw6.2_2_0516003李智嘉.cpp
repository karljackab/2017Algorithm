#include <iostream>
using namespace std;

int a[1020],ans;

void go(int input)
{
	int now=0;
	int step=(now+ans+1)/2;
	while(step>0&&now<ans)
		if(now+step<ans&&input>=a[now+step])
			now+=step;
		else
			step/=2;
	if(!ans||input<a[now])
	{
		if(!ans)
			ans++;
		a[now]=input;
	}
	else 
	{
		if(now==ans-1)
			ans++;
		a[now+1]=input;
	}
}

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>m;
			go(m);
		}
		cout<<ans<<endl;
	}
	return 0;
}