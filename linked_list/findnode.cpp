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

int indexOfNIter(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
    {
        return -1;
    }
    int s=0;
    if(head->data==n)
    {
        return 0;
    }
    
    else 
     s=indexOfNIter(head->next,n);
    
    if(s==-1)
    {
        return -1;
    }
    
    else return s+1;
}


