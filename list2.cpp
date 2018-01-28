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

void remove_unsorted(node *head)
{
	node *ptr1,*ptr2,*temp;

	ptr1=head;

	while(ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2=ptr1;

		while( ptr2->next != NULL)
		{
			if(ptr1->data == ptr2->next->data)
			{
				temp=ptr2->next;
				ptr2->next=temp->next;
				delete(temp);

			}
			else
				ptr2=ptr2->next;
		}

		ptr1=ptr1->next;
	}
}

void remove_unsorted1(node *head)
{
	set<int> visited;//hash

	node *curr=head;
	node *prev=NULL;

	while(curr != NULL)
	{
		if(visited.find(curr->data) != visited.end())
		{
			prev->next=curr->next;
			delete(curr);
		}
		else
		{
			visited.insert(curr->data);
			prev=curr;
		}

		curr=prev->next;//imp
	}

}

void pairwise_iterative(node *head)
{
	node *temp=head;
	int t;

	while(temp != NULL && temp->next != NULL)
	{
		t=temp->data;
		temp->data=temp->next->data;
		temp->next->data=t;

		temp=temp->next->next;
	}
}

void pairwise_recursive(node *head)
{
	if(head != NULL && head->next != NULL)
	{
		int t;
		t=head->data;
		head->data=head->next->data;
		head->next->data=t;

		pairwise_recursive(head->next->next);
	}
}

void split(node *src, node *f, node *r)
{
	node *fast,*slow;

	if(src == NULL || src->next == NULL)
	{
		f=src;
		r=NULL;
	}
	else
	{
		slow=src;
		fast=src->next;

		while(fast != NULL)
		{
			fast=fast->next;
			if(fast != NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}

		f=src;
		r=slow->next;
		slow->next=NULL;
	}

}

node *merge(node *a, node *b)
{
	node *result=NULL;

	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;

	if(a->data <= b->data)
	{
		result=a;
		result->next=merge(a->next,b);
	}
	else
	{
		result=b;
		result->next=merge(a,b->next);
	}

	return result;

}

void merge_sort(node *head)
{
	node *p=head;
	node *a,*b;

	if(p==NULL || p->next == NULL)
		return;

	split(p,a,b);

	merge_sort(a);
	merge_sort(b);

	head= merge(a,b);
}

int main()
{
	//remove duplicates form unsorted list
	node *head=NULL;

	head=create();
	//display(head);
	/*
	//using two loops o(n^2)
	remove_unsorted(head);
	cout<<"\n after removing duplicates :";
	display(head);

	//using hashing
	remove_unsorted1(head);
	cout<<"\n after removing duplicates :";
	display(head);
	*/


	//pairwise swap
	/*
	pairwise_iterative(head);
	display(head);
	cout<<endl;
	pairwise_recursive(head);
	display(head);
	*/

	//mergesort for the linked list
	merge_sort(head);
	display(head);
	return 0;
}