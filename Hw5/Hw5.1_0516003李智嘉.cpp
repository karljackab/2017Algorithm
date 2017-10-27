#include <iostream>
#include <cstring>
using namespace std;

string a[1020];
char b[1020];
int s[1020];

int main()
{
	int t,n,m,result=0;
	string temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			s[i]=1;
			cin>>temp;
			a[i].assign(temp,0,temp.length()-1);
			b[i]=temp[temp.length()-1];
		}
		for(int i=n-2;i>=0;i--)
		{
			m=0;
			for(int j=i+1;j<n;j++)
				if(a[i]==a[j]||b[i]==b[j]||a[i][0]=='8'||a[j][0]=='8')
					if(s[j]>m)
						m=s[j];
			s[i]+=m;
		}
		m=0;
		for(int i=0;i<n;i++)
			if(s[i]>m)
				m=s[i];
		cout<<m<<endl;
	}
	return 0;
}