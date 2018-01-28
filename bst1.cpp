#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int data;
	tree *left;
	tree *right;

};


tree *create()
{
	tree *root;
	root=NULL;
	char ch;
	tree *n,*p;
	int flag;
	do
	{
		int val;
		cout<<"enter the value for the node ";
		scanf("%d", &val);

		n=new tree;
		n->data=val;
		n->left=NULL;
		n->right=NULL;

		if(root == NULL)
			root=n;

		else
		{
			flag=1;
			p=root;

			while(flag == 1)
			{
				if(n->data < p->data)
				{
					if(p->left == NULL)
					{
						p->left=n;
						flag=0;
					}
					else
						p=p->left;
				}

				else
				{
					if(p->right == NULL)
					{
						p->right=n;
						flag=0;
					}
					else
						p=p->right;
				}
			}

		}//root != NULL




		cout<<"\n want to continue ?? ";
		 fflush(stdin);
		cin>>ch;
	}while(ch == 'y');
	
	return root;

}

void inorder(tree *root)
{
	if(root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

tree *find_lca(tree *root, int n1, int n2)
{
	if(root == NULL)
		return NULL;

	if(root->data < n1 && root->data < n2)
		return find_lca(root->right,n1,n2);

	if(root->data > n1 && root->data > n2)
		return find_lca(root->left,n1,n2);

	return root;
}

void inoreder_prescc(tree *root, tree*& pre, tree*& succ, int key)
{
	tree *temp;

	if(root == NULL)
		return ;

	if(root->data == key)
	{
		if(root->left)
		{
			temp=root->left;
			while(temp->right)
				temp=temp->right;

			pre=temp;

		}

		if(root->right)
		{
			temp=root->right;
			while(temp->left)
				temp=temp->left;

			succ=temp;
		}

		return;
		
	}

	else if(key < root->data)
	{
		succ=root;
		inoreder_prescc(root->left, pre,succ, key);


	}

	else
	{
		pre=root;
		inoreder_prescc(root->right, pre,succ, key);

	}


}


bool isbst(tree *root, tree *l=NULL, tree *r= NULL)
{
	if(root == NULL)
		return true;

	if(l && root->data < l->data)
		return false;
	if(r && root->data > r->data)
		return false;

	return isbst(root->left,l,root) && isbst(root->right, root,r);
}

void add_to_nodes(tree *root, int *sum)
{
	if(root == NULL)
		return;
	add_to_nodes(root->right,sum);

	*sum=*sum+root->data;
	root->data=*sum;

	add_to_nodes(root->left, sum);
}

void add_greater(tree *root)
{
	int sum=0;
	add_to_nodes(root, &sum);
}


int main()
{
	tree *root;
	root=NULL;
	root=create();
	inorder(root);

	/*
	//LCA
	int n1,n2;
	cin>>n1>>n2;
	tree *lca=find_lca(root,n1,n2);
	if(lca)
		cout<<endl<<"lca is :"<<lca->data;
	else
		cout<<endl<<" not present ";
		*/

	/*

	int key;
	cin>>key;
	tree *pre=NULL, *succ=NULL;
	inoreder_prescc(root,pre,succ,key);

	if( pre)
		printf("\n predecessor is : %d ", pre->data );
	else
		cout << "No Predecessor";


	if(succ)
		printf("\n successor id  : %d ", succ->data);
	else
		cout << "No Successor";

		*/
/*
	//to check if tree is bst
	if (isbst(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

*/

    //Add all greater values to every node in a given BST
    add_greater(root);
    inorder(root);
	

	return 0;
}