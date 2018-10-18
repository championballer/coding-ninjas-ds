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
node* eliminate_duplicate(node* head)
{
    //write your code here
  	if(head==NULL || head->next==NULL)return head;
  
  	head->next = eliminate_duplicate(head->next);
  	if(head->data==head->next->data)
    return head->next;
  
  	else return head;
  
}
