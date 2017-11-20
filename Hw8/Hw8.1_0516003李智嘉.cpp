#include <iostream>
#include <cstdio>
using namespace std;

typedef struct NODE
{
	int num;
	struct NODE *left,*right;
}node;

void insert(node *now,int num)
{
	while(1)
	{
		while(now->right!=NULL && num>=now->num)
			now=now->right;
		while(now->left!=NULL && num<now->num)
			now=now->left;
		if(now->right==NULL && num>=now->num)
		{
			now->right=new node;
			now=now->right;
			now->right=NULL; now->right=NULL; now->num=num;
			break;
		}
		if(now->left==NULL && num<now->num)
		{
			now->left=new node;
			now=now->left;
			now->left=NULL; now->left=NULL; now->num=num;
			break;
		}
	}
}

void search(node *now,int tg)
{
	while(now->num!=tg)
	{
		if(now->num<tg)
		{
			cout<<"R";
			now=now->right;
		}
		if(now->num>tg)
		{
			cout<<'L';
			now=now->left;
		}
	}
	cout<<endl;
}


int main()
{
	int n,m,now;
	node *root;
	while(cin>>n>>m)
	{
		root=new node;
		root->left=NULL;root->right=NULL;
		cin>>root->num;
		for(int i=1;i<n;i++)
		{
			cin>>now;
			insert(root,now);
		}
		search(root,m);
	}
	return 0;
}