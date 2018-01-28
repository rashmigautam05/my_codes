//create circular linked list

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
			head->next=head;
		}

		else
		{
			n->next=head->next;
			head->next=n;
			head=n;

		}



		cout<<"\n want to continue ??";
		cin>>ch;

	}while(ch == 'y' || ch == 'Y');

	return head;
}//create


void display(node *head)
{
	if(head == NULL)
		printf("\n empty list");

	node *p=head->next;

	do
	{
		printf("%d ", p->data);
		p=p->next;


	}while(p != head->next);

}


node *insert_at_begin(node *head)
{
		node *n;
		int val;
		n= new node;
		cout<<"\n Enter the value for the node ";
		cin>>val;
		n->data=val;
		n->next=NULL;

		if(head == NULL)
		{
			head=n;
			head->next=head;
		}

		else
		{
			n->next=head->next;
			head->next=n;
			

		}

		return head;

}

node *insert_at_end(node *head)
{
		node *n;
		int val;
		n= new node;
		cout<<"\n Enter the value for the node ";
		cin>>val;
		n->data=val;
		n->next=NULL;

		if(head == NULL)
		{
			head=n;
			head->next=head;
		}

		else
		{
			n->next=head->next;
			head->next=n;
			head=n;
			

		}

		return head;

}


node *insert_at_any(node *head,int x)
{
		if(head == NULL)
			return NULL;

		node *p= head->next;
		node *n;

		do
		{
			if(p->data == x)
			{
			int val;
			n= new node;
			cout<<"\n Enter the value for the node ";
			cin>>val;
			n->data=val;
			n->next=NULL;

			n->next=p->next;
			p->next=n;

			if(p == head)
				head=p;
			return head;


			}

			p=p->next;

		}while(p != head->next);

		cout<<"\n item not present in list";

	return head;	
}

void splitll(node *head, node **head1, node **head2)
{

	head=head->next;

	node *fast=head;
	node *slow=head;

	while(fast->next != head && fast->next->next != head)
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	if(fast->next->next == head)
		fast=fast->next;

	*head1=head;


	if(head->next != head)
		*head2 = slow->next;

	fast->next= slow->next;

	slow->next=head;


}

void display1(node *head)
{
	node *temp=head;

	if(head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp= temp->next;

		}while(temp != head);
	}
}

node *sortinsert(node *head)
{
	node *n;
	head= head->next;

	node *p=head;
	int val;
	n= new node;
	cout<<"\n Enter the value for the node ";
	cin>>val;
	n->data=val;
	n->next=NULL;

	if(head == NULL)
	{
		head=n;
		head->next=head;
		return head;

	}

	else if(p->data >=n->data)
	{
		while(p->next != NULL)
			p=p->next;

		p->next=n;
		n->next=head;
		head=n;
		return head;

	}
	else
	{
			while(p->next != head &&  p->next->data <n->data)
				p=p->next;

			n->next=p->next;
			p->next=n;

			return head;

	}





}


int main()
{
	//create circular linked list
	int x;
	node *head=NULL;

	head=create();
	display(head);

	//isertion
	head= insert_at_begin(head);
	display(head);

	head= insert_at_end(head);
	display(head);


	scanf("%d", &x);
	head= insert_at_any(head,x);
	display(head);

	/*
	//split circular ll

	cout<<"\n split \n";
	node *head1=NULL;
	node *head2=NULL;
	splitll(head,&head1,&head2);

	cout<<"\n first part";
	display1(head1);
	cout<<"\n second part";
	display1(head2);
	*/

	//insert into a sorted CLL
	head= sortinsert(head);
	display1(head);




	return 0;
}