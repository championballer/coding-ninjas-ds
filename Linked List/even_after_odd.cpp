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
class helper{
  public:
  node* even;
  node* prev;
};

node* lastNode(node* head)
{
  node* current=head;
  while(current->next!=NULL)
  {
    current=current->next;
  }
  
  return current;
}

helper findEven(node* head)
{
  node* current=head;
  node* trial=head;
    while(current!=NULL)
  {
    if(current->data%2==0)
    {
      break;
    }
    
    else
    {
      trial=current;
      current=current->next;
    }
  }
  
  helper output;
  output.even=current;
  output.prev=trial;

  return output;  
}


bool checkEven(node* head)
{
  node* current=head;
  while(current!=NULL)
  {
    if(current->data%2!=0)
    {
      return false;
    }
    
    else current=current->next;
  }
  return true;
}
node* arrange_LinkedList(node* head)
{
    //write your code here
  	
  	bool checkTwo=checkEven(head);
     if(checkTwo==true)
    {
      return head;
    }
  	node* last=lastNode(head);
  	node* temp=last;
  	while(head->data%2==0)
    {
      temp->next=head;
      temp=temp->next;
      head=head->next;
      temp->next=NULL;
    }
  	helper output=findEven(head);
  	if(output.even==NULL)
    {
      return head;
    }
  
  	
  	while(output.even!=last)
    {
      
      temp->next=output.even;
      temp=temp->next;
      output.prev->next=output.even->next;
      temp->next=NULL;
      
      output=findEven(head);
      
    }
  
  	if(last->data%2==0)
    {
      output=findEven(head);
      temp->next=output.even;
      temp=temp->next;
      output.prev->next=output.even->next;
      temp->next=NULL;
      
    }
  
  	
  return head;
  	
}
