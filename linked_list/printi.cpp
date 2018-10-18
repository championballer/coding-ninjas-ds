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

void printIthNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
    {
        return;
    }
    
    int count=0;
    Node* temp=head;
    
    int size=length(head);
    if(i>=size)
    {
        return;
    }
    while(count!=i)
    {
        temp=temp->next;
        count++;
    }

    cout<<temp->data;
}


