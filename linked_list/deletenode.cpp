/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
int length(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
    {
        return 0;
    }
    
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    
    return count;
}


Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    int count=0;
    Node* temp=head;
    
    if(i==0)
    {
        head=head->next;
        delete temp;
        return head;
    }
    int size=length(head);
    if(i==size)
    {
        return head;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
        
    if(temp!=NULL)
    {
        Node* a=temp->next;
        Node* b=a->next;
        temp->next=b;
        delete a;
    
    }
    
    return head;
}


