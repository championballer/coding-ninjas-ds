#include<iostream>
#include"node.cpp"

using namespace std;

void print(node * head)
{
	node * current = head;
	while(current!=NULL)
	{
	cout<<current->data<<" ";
	current=current->next;
	}

	cout<<endl;
}

node* takeInput()
{
	node * head = NULL;
	node * current = NULL;
	int in;
	cin>>in;
	while(in!=-1)
	{
		node * newnode = new node(in);
		if(head==NULL)
		{
		head = newnode;
		current = head;
		}
		else
		{
		current->next = newnode;
		current = current->next;
		}

		cin>>in;
		
	}
	return head;	
}

node* rev(node* head)
{
	if(head==NULL)return NULL;
	node * tail = head->next;
	head->next=rev(head->next);
	if(tail==NULL)
	{
		return head;
	}
	tail->next = head;
	node * temp = head;
	head=head->next;
	temp->next=NULL;
	return head;
	
	
}

node * swap(node * head, int i,int j)
{	
	if(i!=0 && j!=0)
	{
		node* current1 = head;
		node* current2 = head;
		node* prev1 = NULL;
		node* prev2 = NULL;

		for(int k=0;k<i;k++)
		{
		prev1=current1;
		current1=current1->next;
		}

		for(int k=0;k<j;k++)
		{
		prev2=current2;
		current2=current2->next;
		} 

		prev1->next=current2;
		current1->next=current2->next;
		current2->next=current1;

		return head;
	}

	if(i==0 && j==1)
	{
		node* temp = head;
		head = head->next;
		temp->next = head->next;
		head->next = temp;
		return head;
	}

	if(i==0 && j!=1)
	{

		node* prev=NULL;
		node* current=head;
		for(int k=0;k<j;k++)
		{
			prev=current;
			current=current->next;
		}
		node* temp = head;
		node* temp2 = current->next;
		head = current;
		head->next = temp->next;
		prev->next = temp;
		temp->next = temp2;
		return head;
	}
	
}

node* append(node * head, int n)
{

	head = rev(head);
	node * prev =NULL;
	node* current = head;
	for(int i=0;i<n;i++)
	{
		prev=current;
		current = current->next;
	}

	prev->next = rev(current);
	return head;

}


int main()
{

	//static allocation
	/*node n1(20);
	node n2(30);
	node* head2= &n1;//using variable header as would be required for linked lists
	n1.next = &n2;
	cout<<n1.data<<endl;
	cout<<(n1.next)->data<<endl;

	//dynamic allocation
	node * head=new node(10);
	node * ptr =new node(20);
	head->next=ptr;//the arrow can be seen as indirect referencing as well
	node * current=head;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}*/

	node * head = takeInput();
	print(head);
	node * out = swap(head,0,3);
	print(out);
	
}

