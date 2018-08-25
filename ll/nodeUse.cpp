#include<iostream>
#include"node.cpp"

using namespace std;

node<int>* takeInput()
{
	int data;
	cout<<"Please enter data for head:";
	cin>>data;
	node<int>* head=NULL;
	node<int> * current = head;
	while(data!=-1)
	{
		
		node<int> * front = new node<int>(data);
		if(head==NULL)
		{
			head = front;
			current = head;
			cout<<"Please enter data for next node:";
			cin>>data;
			continue;
		}
		
		current->next = front;
		current = front;
		cout<<"Please enter data for next node:";
		cin>>data;
	}
	
	return head;
}

node<int>* insert(node<int>* head,int pos, int data)
{
	if(head==NULL && pos!=0)
	{
		return NULL;
	}
	
	if(pos==0)
	{
		node<int> * front = new node<int>(data);
		front->next = head;
		return front;		
	}
	
	head->next =  insert(head->next,pos-1,data);
}

node<int>* deleteEle(node<int>* head, int pos)
{
	if(pos==0)
	{
		node<int> * temp = head->next;
		delete head;
		return temp;
	}
	
	head->next = deleteEle(head->next,pos-1);
}

void print(node<int> * head)
{
	node<int> * current = head;
	while(current!=NULL)
	{	
		if(current->next==NULL)
		{
			cout<<current->data;
			break;
		}
		cout<<current->data<<"->";
		current = current->next;
	}
	cout<<endl;
}



node<int>* fS(node<int>* head)
{
	node<int> * fast = head;
	node<int> * slow = head;
	
	while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}

node<int>* rev(node<int>* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}

	node<int>* temp = rev(head->next);
	node<int>* end = head->next;
	end->next = head;
	head->next = NULL;
	return temp;	
}

int checkPalindrome(node<int>* node1,node<int>* node2)
{
    if(node1==NULL && node2==NULL)
    {
        return 1;
    }
    
    if(node1->next==NULL && node2==NULL)return 1;
    
    if(node1==NULL || node2==NULL)return 0;
    
    if(node1->data!=node2->data)return 0;
    else return checkPalindrome(node1->next,node2->next);
}


node<int>* mergeLL(node<int>* head1,node<int>* head2)
{
	node<int>* nhead = NULL;
	node<int>* current = nhead;
	node<int>* front;
	while(head1!=NULL && head2!=NULL)
	{
		
		if(head1->data<head2->data)
		{
			front = new node<int>(head1->data);
			head1 = head1->next;	
		}
		
		else
		{
			front = new node<int>(head2->data);
			head2 = head2->next;
		}
		
		if(nhead==NULL)
		{
			nhead=front;
			current=nhead;
		}
		
		else
		{
			current->next = front;
			current = front;
		}
		
	}
	
	while(head1!=NULL)
	{
		front = new node<int>(head1->data);
		head1 = head1->next;
		current->next = front;
		current = front;
	}
	
	while(head2!=NULL)
	{
		front = new node<int>(head2->data);
		head2 = head2->next;
		current->next = front;
		current = front;
	}
	
	return nhead;
}

int lPalin(node<int>* A) {
    
    if(A==NULL)return 1;
    if(A->next==NULL)return 1;
    if(A->next->next==NULL)
    {
        return A->data==A->next->data;
    }
    node<int>* slow = fS(A);
    slow->next = rev(slow->next);
    node<int> * mid = slow->next;
    slow ->next = NULL;
    return checkPalindrome(A,mid);
    
    
}


node<int>* mergeSort(node<int>* head)
{
	if(head==NULL || head->next==NULL)return head;
	node<int>* mid = fS(head);
	cout<<mid->data<<endl;
	cout<<head->data<<endl;
	node<int>* other = mid->next;
	cout<<other->data<<endl;
	mid->next = NULL;
	head = mergeSort(head);
	other = mergeSort(other);
	
	head = mergeLL(head,other);
	
	return head;
}



int main()
{
	node<int> * head = takeInput();
	//print(head);
	//head = deleteEle(head,4);
	//print(head);
	/*node<int> * mid = middle(head);
	cout<<mid->data<<endl;
	*/
	
	//head = mergeSort(head);
	cout<<lPalin(head)<<endl;
}
