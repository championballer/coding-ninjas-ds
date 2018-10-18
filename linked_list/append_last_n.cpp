//head is the head of the linked list and n is  how many element you want to append from the last to the front
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* append(node* head)
{
    node* temp=head;
    node* temp2=temp->next;
    while(temp2->next!=NULL)
    {
        temp=temp->next;
        temp2=temp2->next;
    }
    
    node* a=temp->next;
    temp->next=NULL;
    a->next=head;
    return a;
}
node* append_LinkedList(node* head,int n)
{
    //write your code here
    
    for(int i=0;i<n;i++)
    {
        head=append(head);
    }
    
    return head;
}
