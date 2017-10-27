#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	int two;
	int five;
}node;

int main()
{
	int n,a,b;
	node result[305][305],temp;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>a;
			while(a&&!(a%5))
			{
				a/=5;
				result[i][j].five++;
			}
			while(a&&!(a%2))
			{
				a/=2;
				result[i][j].two++;
			}
			temp.two=0;
			temp.five=0;
			if(i-1>=0)
				temp=result[i-1][j];
			if(j-1>=0)
				if(i-1<0)
					temp=result[i][j-1];
				else
				{
					if(result[i][j-1].five<temp.five)
						temp.five=result[i][j-1].five;
					if(result[i][j-1].two<temp.two)
						temp.two=result[i][j-1].two;
				}
			result[i][j].two+=temp.two;
			result[i][j].five+=temp.five;
		}
	cout<<min(result[n-1][n-1].two,result[n-1][n-1].five)<<endl;
	return 0;
}