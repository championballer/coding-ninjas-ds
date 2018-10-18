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

void print_linkedlist_spl(node*head)
{
    //write your code here
    if(head==NULL)
    {
        return;
    }
    
    print_linkedlist_spl(head->next);
    
    cout<<head->data<<" ";
}
