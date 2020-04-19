//head is the head of the linked list
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

int length(node* head)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    
    return count;
}

node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    int size=length(head);
    int itr=0;
    while(itr<size)
    {
        node* current=head;
        node* prev=NULL;
        while(current->next!=NULL)
        {
            if(current==head)
            {
                if(current->data>current->next->data)
                {
                node* temp=current->next;
                current->next=current->next->next;
                temp->next=current;
                head=temp;
                }
                
                else current=current->next;
                
                prev=head;
            }
            
            else{
                if(current->data>current->next->data)
                {
                node* temp=current->next;
                current->next=current->next->next;
                prev->next=temp;
                temp->next=current;
                }
                
                else current=current->next;
                prev=prev->next;
            }
            
        }
        itr++;
    }
    
    return head;
}
