//head is head of linked list,i is the index, data is data of your node
// Following is the node structure
/**************
 class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
 };
***************/

Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
    {
        return head;
    }
    
    
    if(i==0)
    {
        Node* newNode=new Node(data);
        newNode->next=head;
        return newNode;
    }
    else     
    head->next=insertNodeRec(head->next,i-1,data);
    return head;
}



