#include<iostream>
#include"node.cpp"

using namespace std;

Node<int>* takeInput()
{
	int i = 0;
	cin>>i;
	Node<int>* head = NULL;
	Node<int>* current = NULL;
	while(i!=-1)
	{
		Node<int> * in = new Node<int>(i);
		if(head==NULL)
		{
			head = in;
			current = in;
		}

		else
		{
			current->next = in;
			current = current->next;
		}

		cin>>i;
	}

	return head;
}

void printList(Node<int>* head)
{
	Node<int>* current = head;
	while(current!=NULL)
	{
		if(current->next==NULL)
		{
			cout<<current->data<<endl;
		}

		else cout<<current->data<<"->";
		current = current->next;
	}


}

Node<int>* rev(Node<int> * head)
{
	if(head==NULL || head->next==NULL)return head;

	Node<int> * temp = rev(head->next);
	Node<int> * temp2 = head->next->next;
	head->next->next = head;
	head->next = temp2;
	return temp;
}

Node<int>* addOne(Node<int> * head)
{
	Node<int>* aux = rev(head);

	Node<int>* current = aux;
	int sum = 0;
	int carry = 1;
	while(current!=NULL)
	{
		sum = (current->data+carry);
		carry = sum/10;
		sum = sum%10;

		current->data = sum;
		if(current->next==NULL && carry==1)
		{
			Node<int> * unit = new Node<int>(1);
			current->next = unit;
			break;
		}

		current = current->next;
	}

	Node<int> * result = rev(aux);

	return result;
}

int main()
{
	Node<int> * head = takeInput();
	printList(head);
	Node<int>* revhead = rev(head);
	printList(revhead);
	//printList(head);
	Node<int>* output = addOne(revhead);
	printList(output);
}