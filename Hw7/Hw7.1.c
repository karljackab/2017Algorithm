#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t,n,m,count,now;
	char temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		count=0;now=0;
		while(n--)
		{
			while(temp=getchar())
				if(temp<='9'&&temp>='0')
					break;
			now=now*10+temp-'0';
			now%=m;
			if(!now)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;	
}