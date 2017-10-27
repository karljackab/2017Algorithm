#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long int f(long long int x,long long int n)
{
	return abs(x)%n;
}


typedef struct n
{
	struct n *next;
	long long int value;
	long long int count;
}Node;

class hs
{
private:
	Node **node;
	int n;
public:
	hs(int n)
	{
		this->n=n;
		node=new Node*[n];
		for(int i=0;i<n;i++)
		{
			node[i]=new Node;
			node[i]->next=NULL;
		}
	}
	~hs()
	{
		for(int i=0;i<n;i++)
			delete []node[i];
		delete []node;
	}
	void reset(int n)
	{
		for(int i=0;i<n;i++)
			node[i]->next=NULL;
	}
	void insert(long long int key,long long int value)
	{
		Node *ptr=node[key];
		while(ptr->next!=NULL&&ptr->value!=value)
			ptr=ptr->next;
		if(ptr->next==NULL)
		{
			ptr->value=value;
			ptr->count=1;
			ptr->next=new Node;
			ptr->next->next=NULL;
		}
		else
			ptr->count++;
	}
	long long int search(long long int key,long long int value)
	{
		Node *ptr=node[key];
		long long int c=0;
		while(ptr->next!=NULL)
		{
			if(ptr->value==value)
			{
				c=ptr->count;
				break;
			}
			ptr=ptr->next;
		}
		return c;
	}
};

long long int a[100000];

int main()
{
	int T;
	long long int n,k,i,j,n2=100000;
	
	cin>>T;
	hs t(n2);
	while(T--)
	{
		cin>>n>>k;
		
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			t.insert(f(a[i],n2),a[i]);
		}
		long long int c=0;
		for(i=0;i<n;i++)
		{
			c+=t.search(f(k-a[i],n2),k-a[i]);
			if(k-a[i]==a[i])
				c--;
		}
		cout<<c/2<<endl;
		t.reset(n2);
	}
	return 0;
}