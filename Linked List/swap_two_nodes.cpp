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

node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    node* current=head;
    while(current!=NULL)
    {
        for(int i=1;i<M;i++)
        {
            if(current->next==NULL)
            {
                break;
            }
            current=current->next;
        }
        
        if(current==NULL || current->next==NULL)
        {
            break;
        }
        for(int i=0;i<N;i++)
        {
            if(current->next==NULL)
            {
                break;
            }
            node* temp=current->next;
            current->next=current->next->next;
            delete temp;
        }
        if(current->next!=NULL)
        current=current->next;
    }
    
    return head;
    
    

}
