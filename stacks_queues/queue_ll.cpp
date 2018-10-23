/*******
#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

#include "Queue.h"
int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            cout << q.isEmpty() << endl;
        }
        cin >> choice;
    }
    
}

*******/




template<typename T>
class Queue {
    Node<T> * head;
  	Node<T> * tail;
  	int size;
    
    public :
    
    
    Queue() {
        head=NULL;
      	tail=NULL;
      	size=0;
    }
    
    void enqueue(T data) {
        Node<T> * temp = new Node<T>(data);
      	if(head==NULL)
        {
          head=temp;
          tail=temp;
        }
      
      	else
        {
          tail->next=temp;
          tail=temp;
        }
      
      	size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
      	if(size==0)
        {
          return 0;
        }
      
      	T ans = head->data;
      	Node<T> * temp = head;
      	head=head->next;
      	delete temp;
      	size--;
      	return ans;
    }
    
    T front()  {
        // Return 0 if queue is empty
      	if(size==0)
        {
          return 0;
        }
      
      	return head->data;
    }
};
