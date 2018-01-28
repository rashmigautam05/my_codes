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


/*
node *reversekalt(node *head, int k)
{
	int count=0;
	node *prev=NULL;
	node *curr=head;
	node *nex=NULL;

	while(curr != NULL && count<k)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;

		count++;
	}

	if(head != NULL)
		head->next=curr;

	count=0;
	while(count<k-1 && curr != NULL)
	{
		curr=curr->next;
		count++;
	}

	
	if(curr!= NULL)
		curr->next=reversek(curr->next,k);

	return prev;

}


node *reversek(node *head, int k)
{
	int count=0;
	node *prev=NULL;
	node *curr=head;
	node *nex=NULL;

	while(curr != NULL && count<k)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;

		count++;
	}

	if(nex != NULL)
		head->next=reversek(nex,k);

	return prev;

}

*/


node *reverse(node *head)
{
	node *curr=head;
	node *prev=NULL;
	node *nex=NULL;

	while(curr != NULL)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;
	}

	head=prev;

	return head;


}

node *greater_value(node *head)
{
	head=reverse(head);

	int max= head->data;

	node *p=head;
	node *q;

	while(p!= NULL && p->next != NULL)
	{
		if(p->next->data < max)
		{
			q=p->next;
			p->next=q->next;
			delete(q);
		}
		else
		{
			p=p->next;
			max=p->data;
		}
	}
	

	head=reverse(head);

	return head;

	
	
}

/*

node *sagregate1(node *head)
{
	node *even_head=NULL;
	node *odd_head=NULL;
	node *peven=NULL;
	node *podd=NULL;

	node *curr=head;
	int val;

	while(curr != NULL)
	{
		val=curr->data;

		if(val %2 ==0)
		{
			if(even_head == NULL)
			{
				even_head=curr;
				peven=even_head;
			}
			else
			{
				peven->next=curr;
				peven=peven->next;
			}
		}//even

		else
		{
			if(odd_head == NULL)
			{
				odd_head=curr;
				podd=odd_head;
			}
			else
			{
				podd->next=curr;
				podd=podd->next;
			}

		}//odd

		curr=curr->next;

	}//while

	peven->next=odd_head;
	podd->next=NULL;
	head=even_head;

	return head;

}

*/

node *sagregate2(node *head)
{
	node *end=head;
	node *new_end;//for traversing the end;
	node *prev=NULL;//to keep the track of even list

	node *curr=head;

	while(end->next != NULL)
		end=end->next;

	new_end=end;

	while((curr->data %2 != 0) && curr!=end)
	{
		new_end->next=curr;
		curr=curr->next;
		new_end->next->next=NULL;
		new_end=new_end->next;
	}

	if(curr->data %2 == 0)
	{
		head=curr;
		while(curr != end)
		{
			if(curr->data %2 == 0)
			{
				prev=curr;
				curr=curr->next;

			}
			else
			{
				prev->next=curr->next;
				curr->next=NULL;
				new_end->next=curr;
				new_end=new_end->next;

			}
		}//while
	}

	else
		prev=curr;

    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }

    return head;
}

node *addtwo(node *head1, node *head2)
{
	int sum=0,carry=0;
	node *result=NULL;
	node *n,*p;


	while(head1 != NULL || head2 != NULL)
	{
		sum=carry+ (head1? head1->data : 0)+ (head2? head2->data : 0);

		carry= (sum>=10) ? 1:0;
		sum=sum%10;

		n=new node;
		n->data=sum;
		n->next=NULL;

		if(result == NULL)
		{
			result=n;
			p=result;

		}
		else
		{
			p->next=n;
			p=n;
		}

		if(head1)
			head1=head1->next;
		if(head2)
			head2=head2->next;


	}

	if(carry > 0)
	{
		n=new node;
		n->data=sum;
		n->next=NULL;
		p->next=n;

	}

	return result;
}


void swapointers(node *head1, node *head2)
{
	node *temp;
	temp=head1;
	head1=head2;
	head2=temp;
}

node *addsamesize(node *head1, node *head2, int *carry)
{
	if(head1 == NULL)
		return NULL;

	int sum;

	node *n=new node;
	n->next=addsamesize(head1->next,head2->next,carry);

	sum= head1->data + head2->data + (*carry);

	*carry=sum/10;
	sum=sum%10;

	n->data=sum;

	return n;

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


node * addremaing(node *head1, node *curr, int *carry)
{
	int sum;
	node *n;

	if(head1 != curr)
	{
		
		n->next=addremaing(head1->next,curr,carry);

		sum=head1->data + *carry;
		*carry=sum/10;
		sum=sum%10;

		n->data=sum;


	}

	return n;

}


node *addtwoactual(node *head1, node *head2)
{
	node *res=NULL;
	node *curr;

	if(head1 == NULL)
	{
		res=head2;
		return res;

	}
	else if(head2 == NULL)
	{
		res=head1;
		return res;

	}

	int carry=0;

	int size1=count(head1);
	int size2=count(head2);

	if(size1 == size2)
		res=addsamesize(head1,head2,&carry);

	else
	{
		int diff=abs(size1-size2);

		if(size1<size2)
			swapointers(head1,head2);

		for(curr=head1; diff--; curr=curr->next);

		res=addsamesize(curr,head2,&carry);

		res=addremaing(head1,curr,&carry);


	}

	if(carry)
	{
		node *n=new node;
		n->data=carry;
		n->next=res;
		res=n;
	}

	

	return res;

}

int main()
{
	node *head=NULL;
	node *head1=NULL;

	head=create();
	display(head);
	/*
	//revere list in group of size k
	int k;
	scanf("%d", &k);
	 head= reversek(head,k);
	display(head);

	//revere alternating k nodes
	node *rev=reversekalt(head,k);
	display(rev);
	*/
	//delete the node which have greater value at right side
	// reversing o(n).

	//head=greater_value(head);
	//display(head);

	// segregate even and odd value nodes
	/*head=sagregate1(head);
	display(head);

	head=sagregate2(head);
	display(head);
	*/

	//add two numbers represented by linked list
	head1=create();
	display(head1);

	//add two number of two lists
	//where least significant digit is first node of lists and most significant digit is last node.
	node *res=addtwo(head,head1);
	display(res);

	node *res1=addtwoactual(head,head1);
	display(res1);






	return 0;
}