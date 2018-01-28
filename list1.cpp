#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

node *create()
{
	char ch;
	node *head=NULL;
	node *n,*p;
	int val;

	do
	{
		n= new node;
		cout<<"\n Enter the value for the node ";
		cin>>val;
		n->data=val;
		n->next=NULL;

		if(head == NULL)
		{
			head=n;
		}

		else
		{
			p=head;

			while(p->next !=NULL)
				p=p->next;

			p->next=n;

		}



		cout<<"\n want to continue ??";
		cin>>ch;

	}while(ch == 'y' || ch == 'Y');

	return head;
}//create

void display(node *head)
{
	if(head == NULL)
		cout<<"list is empty ";
	else
	{
		node *p=head;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
	}
}


int count(node *head)
{
	int count=0;
	if(head == NULL)
		printf("\n 0");
	else
	{
		node *p =head;
		while( p!= NULL)
		{
			count++;
			p=p->next;
		}

		printf("%d \n", count);
	}

	return count;
}

void search(node *head, int x)
{
	if(head == NULL)
		printf("\n not found");
	else
	{
		node *p=head;
		int flag=0,count=1;

		while(p != NULL)
		{
			if(p->data == x)
			{
				flag =1;
				break;
			}

			p=p->next;
			count++;

		}//while

		if(flag == 1)
			printf("%d is found at position %d " , x,count);
		else
			printf("%d is not found ", x);
	}//else
}

node * insert(node *head, int x, int pos)
{
	int total= count(head);
	node *n,*p,*o;

	if( pos <1 || pos > (total+1))
		printf("\n invalid position");
	else
	{
		n = new node;
		n->data=x;
		n->next=NULL;

		if(pos ==1)
		{
			n->next = head;
			head=n;
		}
		else
		{
			p=head;
			for(int i=1; i<pos ;i++)
			{
				o=p;
				p=p->next;
			}

			o->next=n;
			n->next = p;
		}

	}//else

	return head;

}

node *deletenode(node *head)
{
	int pos;
	int total = count(head);
	node *p,*o;

	printf("\n Enter the position of the node to be deleted");
	scanf("%d", &pos);

	if(pos<1 || pos>total )
		printf("\n invalid position");
	else
	{
		if(pos == 1)
		{
			p=head;
			head=head->next;
			delete(p);
		}
		else
		{
			p=head;
			for(int i=1;i<pos; i++ )
			{
				o=p;
				p=p->next;


			}

			o->next = p->next;
			delete(p);
		}

	}

	return head;

}


node *delkey(node *head)
{
	int val;
	printf("\n Enter the value of node to be deleted");
	scanf("%d", &val);

	node *p=head;
	node *o;
	int flag=0;
	while(p != NULL)
	{
		if(p->data == val)
		{
			flag=1;
			break;
		}
		o=p;
		p=p->next;


	}

	if(flag ==1)
	{
		o->next= p->next;
		delete(p);
	}
	else
		printf("\n key is not present");

	return head;
}

int getlength(node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1+ getlength(head->next);
}

int searecur(node *head, int x)
{
	if(head == NULL)
		return 0;
	else
	{
		if(head->data == x)
			return 1;
		else
			return searecur(head->next,x);
	}
}

void swapnodes(node *head, int x, int y)
{
	if(x == y)
		return ;

	node *prevx=NULL;
	node *currx=head;

	while(currx && currx->data != x)
	{
		prevx=currx;
		currx= currx->next;
	}


	node *prevy=NULL;
	node *curry=head;

	while(curry && curry->data != y)
	{
		prevy=curry;
		curry= curry->next;
	}

	if(currx== NULL || curry == NULL)
		return;

	if(prevx == NULL)
		head=curry;
	else
		prevx->next=curry;

	if(prevy == NULL)
		head=currx;
	else
		prevy->next=currx;

	node *temp=currx->next;
	currx->next=curry->next;
	curry->next=temp;
}

int getnthnode(node *head, int n)
{
	if(head == NULL)
		return -1;

	if(n > count(head) || n<0)
		return -1;

	node *p=head;
	for(int i=0;i<n;i++)
		p=p->next;

	return p->data;
}

void middle(node *head)
{
	if(head == NULL)
		printf("\n empty list");
	else
	{
		/*
		node *fast=head;
		node *slow=head;

		while( fast!= NULL && fast->next != NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}

		printf("%d is the middle node ", slow->data);
		*/
		int count=0;
		node *mid=head;

		while(head != NULL)
		{
			if(count & 1)
				mid=mid->next;

			count++;
			head=head->next;
		}

		printf("%d is the middle node ", mid->data);

	}
}

void nth_fromend(node *head, int n)
{
	//o(n)
	/*
	int total=count(head);
	int k=total-n+1;

	node *p=head;
	for(int i=1;i<k;i++)
		p=p->next;

	printf("\n nth node from end is : %d", p->data);
	*/
	//using two pointers o(n)

	node *p=head;
	node *q=head;

	for(int i=1;i<n;i++)
		p=p->next;

	while(p->next !=NULL)
	{
		p=p->next;
		q=q->next;
	}

	printf("\n nth node from end is : %d", q->data);

}

node *del(node *head)
{
	if(head == NULL)
		return NULL;

	while(head != NULL)
	{
		node *p=head;
		head=head->next;
		delete(p);
	}

	return head;
}

node *reverse(node *head)
{
	node *prev=NULL;
	node *curr=head;
	node *ahead;

	while(curr != NULL)
	{
		ahead=curr->next;
		curr->next=prev;
		prev=curr;
		curr=ahead;
	}

	head=prev;

	return head;
}

int detectloop(node *head)
{
	node *slow=head;
	node *fast=head;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if( slow == fast)
			return 1;

	}

	return 0;

}


int main()
{
	node *head=NULL;

	int ch,x,pos,total,ans,y;

	do
	{
		cout<<"\n 1.create linked list"<<"\n 2.print linked list"<<"\n 3.count no. of nodes "<<"\n 4.search node"<<"\n 5. insert a node"<<"\n 6.delete a node" 
		<<" \n 7.delete node by key value"<<"\n 8.find length in recursive way"<<"\n 9.search recursively"<<"\n 10.swap nodes"
		<<"\n 11.get nth node "<<"\n 12. middle of linked list"<<"\n 13.print nth node from end"<<"\n 14.delete a linked list"
		<<"\n 15.reverse linked list"<<"\n 16.recursive reversal"<<"\n 17.detect loop";
		cout<<"\n Enter a choice";
		cin>>ch;

		switch(ch)
		{
			case 1:
				head= create();
				break;
			case 2:
				display(head);
				break;
			case 3:
				total=count(head);
				break;
			case 4:
				printf("\n Enter the value to be searched ");
				scanf("%d", &x);
				search(head,x);

				break;
			case 5:
				printf("\n Enter the value to be inserted and the position ");
				scanf("%d %d", &x, &pos);
				head=insert(head,x,pos);
				break;	
			case 6:
				head= deletenode(head);
				break;	
			case 7:
				head=delkey(head);	
				break;	
			case 8:
				cout<<"\n length is : " <<getlength(head);
				break;	

			case 9:
				printf("\n enter the value to be searched ");
				scanf("%d", &x);
				ans= searecur(head,x);
				if(ans == 0)
					printf("\n not found");
				else
					printf("\n found");
				break;	

			case 10:
				printf("\n Enter the nodes to be swapped :");
				scanf("%d %d", &x,&y);
				swapnodes(head,x,y);

				break;	

			case 11:
				printf("\n enter the index of the node ");
				scanf("%d", &x);
				cout<<getnthnode(head,x);
				break;	

			case 12:
				middle(head);
				break;	

			case 13:
				scanf("%d", &x);
				nth_fromend(head,x);
				break;	

			case 14:
				head= del(head);
				break;

			case 15:
				head=reverse(head);
				break;		

			case 16:
				//recursive_reverse(head);
				break;	

			case 17:
					head->next->next->next=head->next;
					ans=detectloop(head);

					if(ans==0)
						printf("\n no loop");
					else
						printf("\n loop found");
				break;	
			case 20:
				break;	


		}//switch

	}while(ch != 20);
	return 0;
}