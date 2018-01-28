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

void merge_list(node *head1, node *head2)
{
	node *result_head=NULL;
	node *p;
	node *n;

	while(1)
	{
		if(head1== NULL)
		{
			if(result_head == NULL)
				result_head=head2;
			break;
		}
		else if(head2 == NULL)
		{
			if(result_head == NULL)
				result_head=head1;
			break;
		}



		if(head1->data <= head2->data)
		{
			n = new node;
			n->data=head1->data;
			n->next=NULL;

			if(result_head == NULL)
			{
				result_head=n;
				p=result_head;
			}
			else
			{
				p->next=n;
				p=n;

			}


			
			
			head1=head1->next;
		}
		else
		{
			n = new node;
			n->data=head2->data;
			n->next=NULL;

			if(result_head == NULL)
			{
				result_head=n;
				p=result_head;
			}
			else
			{
				p->next=n;
				p=n;

			}


			
			
			head2=head2->next;

		}//else

	}//while

	if(head1 == NULL)
		p->next=head2;
	else
		p->next=head1;

	display(result_head);

	


}

node *merge_list_recur(node *head1, node *head2)
{
	node *result=NULL;

	if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;

	if(head1->data <= head2->data)
	{
		result=head1;
		result->next= merge_list_recur(head1->next,head2);
	}
	else
	{
		result=head2;
		result->next= merge_list_recur(head1,head2->next);

	}

	return result;

}

void movedata(node **dest, node **src)
{
	node *n=*src;
	assert(n != NULL);
	*src=n->next;
	n->next=*dest;
	*dest=n;

}

node *merge_list_dummy(node *head1, node *head2)
{
	node dummy;
	node *tail= &dummy;

	dummy.next=NULL;

	while(1)
	{
		if(head1 == NULL)
		{
			tail->next=head2;
			break;
		}
		else if(head2 == NULL)
		{
			tail->next=head1;
			break;

		}

		if(head1->data <= head2->data)
			movedata(&(tail->next), &head1);
		else
			movedata(&(tail->next), &head2);

		tail=tail->next;


	}//while

	return (dummy.next);
}

node *insert(node *head1, int x)
{
	node *n = new node;
	n->data=x;
	n->next=NULL;

	if(head1 == NULL)
		head1=n;
	else
	{
		node *p=head1;

		while(p->next != NULL &&  p->next->data < n->data)
		{
			p=p->next;
		}

		n->next=p->next;
		p->next=n;

	}

	return head1;
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

bool compare_list(node *head1, node *head2)
{
	node *a=head1;
	node *b=head2;

	while(a && b)
	{
		if(a->data == b->data)
		{
			a=a->next;
			b=b->next;
		}

		else
			return 0;
	}

	if(a == NULL && b== NULL)
		return 1;

	return 0;
}

bool ispalindrome(node *head1)
{
	node *fast=head1;
	node *slow=head1, *prev_slow=head1;
	node *mid=NULL, *second_half=NULL;
	bool res=true;

	if(head1 != NULL && head1->next !=NULL)
	{
		while(slow && fast && fast->next != NULL)
		{
			fast=fast->next->next;
			prev_slow=slow;
			slow=slow->next;

		}

		if(fast != NULL)//odd no. of nodes
		{
			mid=slow;
			slow=slow->next;

		}

		second_half=slow;
		prev_slow->next=NULL;
		second_half = reverse(second_half);
		res= compare_list(head1, second_half);

		second_half= reverse(second_half);

		if(mid != NULL)//odd no. of nodes
		{
			prev_slow->next=mid;
			mid->next=second_half;
		}
		else
			prev_slow->next=second_half;


	}//if

	return res;

	
}

int getlength(node *head)
{
	if(head == NULL)
		return 0;
	else
		return 1+ getlength(head->next);
}

int getintersectionnode(node *head1, node *head2, int d)
{
	node *p1=head1;
	node *p2=head2;
	int i;

	for(i=0;i<d;i++)
	{
		if(p1==NULL)
			return -1;
		p1=p1->next;
	}

	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data == p2->data)
			return p1->data;
		p1=p1->next;
		p2=p2->next;
	}

	return -1;

}

int getintersection(node *head1, node *head2)
{
	int len1=getlength(head1);
	int len2=getlength(head2);
	int d;

	if(len1 > len2)
	{
		d= len1-len2;
		return getintersectionnode(head1,head2,d);

	}
	else
	{
		d= len2-len1;
		return getintersectionnode(head2,head1,d);


	}

}

void remove_duplicate(node *head1)
{
	if(head1== NULL)
		return ;
	node *p=head1;

	while(p->next != NULL)
	{
		if(p->data == p->next->data)
		{
			node *temp=p->next;
			p->next=temp->next;
			delete(temp);
		}
		else
			p=p->next;
	}
}

node *intersection_dummy(node *head1, node *head2)
{
	node dummy;
	node *tail= &dummy;
	dummy.next=NULL;
	node *n;

	while(head1 != NULL && head2!= NULL)
	{
		if(head1->data == head2->data)
		{
			n= new node;
			n->data = head1->data;
			n->next= NULL;
			tail->next=n;
			tail=tail->next;

			head1=head1->next;
			head2=head2->next;

		}

		else if(head1->data < head2->data)
			head1=head1->next;
		else
			head2=head2->next;
	}

	return dummy.next;
}


bool ispresent(node *head, int x)
{
	node *p=head;
	while(p != NULL)
	{
		if(p->data == x)
			return 1;

		p=p->next;
	}

	return 0;

}



node *getunion(node *head1, node *head2)
{
	node *result=NULL;
	node *n, *t;

	node *p1=head1, *p2=head2;

	while(p1!= NULL)
	{
		n=new node;
		n->data= p1->data;
		n->next=NULL;
		if(result == NULL)
		{
			result=n;
			t=result;
		}

		else
		{
			t->next=n;
			t=n;
		}

		p1=p1->next;

	}

	while(p2 != NULL)
	{
		if(! ispresent(result,p2->data))
		{
			n=new node;
			n->data= p2->data;
			n->next=NULL;
			if(result == NULL)
			{
				result=n;
				t=result;
			}

			else
			{
				t->next=n;
				t=n;
			}

		}

		p2=p2->next;

	}

	return result;

}

node *adding_list(node *head1, node *head2)
{
	
}



int main()
{
	int x;
	node *head1=NULL;
	node *head2=NULL;

	head1=create();
	
	head2=create();

	display(head1);
	display(head2);

	cout<<"\n \n";/*
	merge_list(head1,head2);
	node *final= merge_list_recur(head1,head2);
	cout<<endl<<endl;
	cout<<"recursion  :  ";
	display(final);

	node *res= merge_list_dummy(head1,head2);
	cout<<endl<<endl;

	cout<<"dummy  :  ";
	display(res);
	

	cout<<endl<<endl;
	printf("Enter the valu of node to be inserted in sorted list");

	scanf("%d", &x);
	head1=insert(head1,x);
	display(head1);
	

	bool f= ispalindrome(head1);
	if( f == true)
		printf("\n yes ...linked list is palnidrome");
	else
		printf("\n no ...linked list is  not palnidrome");
	*/
	// for intersection of two linked list
	/*
	head1->next->next->next=head2->next;

	printf("\n the node of intersection is %d : ", getintersection(head1,head2));
	*/

	///remove duplicates
	/*
	remove_duplicate(head1);
	display(head1);
	*/

	//intersection of two lists
	node *inti= intersection_dummy(head1,head2);
	cout<<"\nintersection is :";
	display(inti);

	//union of two linked list
	node *uni= getunion(head1,head2);
	cout<<"\nunion is :";
	display(uni);

	//add numbers of two lists
	node *add= adding_list(head1,head2);
	display(add);

	

	
	return 0; 
}