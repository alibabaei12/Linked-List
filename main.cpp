#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};
Node* head = NULL;
void insertBeg(int);
void insertEnd(int);
void insert(int, int);
void deleteNode(int);
void reversePrint();
void print();
int main()
{

  insertBeg(5);
  insertBeg(0);
  insertBeg(2);
  insertBeg(1);
  insertBeg(2);
  insertBeg(4);
  insertBeg(2);
  insertBeg(1);
  insertBeg(4);
  insertBeg(5);
  insertBeg(3);
  insertBeg(34);
  insertBeg(45);
  insertBeg(56);
  insertBeg(5);
  insertBeg(1);
  insertBeg(2);
  insertBeg(3);
  insertBeg(4);
  insertBeg(5);


  insert(0 , 6);

  deleteNode(0);

  cout << "print in normal order: " << endl;
  print();

  cout << "Print in reverse order: " << endl;
  reversePrint();


}

void insertBeg(int x){
   Node* ptr = new Node;
   ptr->data = x;
   ptr->next = head;
   head = ptr;
}

void insertEnd(int x){
  Node* ptr = new Node;
  ptr->data = x;
  ptr->next = NULL;
  if(head == NULL) // if List is empty
  {
      head = ptr;
  }

  else{
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
  }

}

void insert(int index, int d)
{
  Node* n = new Node;
  n->data = d;

  if(index == 0)
  {
      insertBeg(d);
      return;
  }

  Node* temp = head->next;
  Node* pre = head;

  for(int i = 0 ; i < index - 1; i++){
      temp = temp->next;
      pre = pre->next;
  }

    pre->next = n;
    n->next = temp;
}

void deleteNode(int index){
  //if list empty
  if(head == NULL){
    cout << "Node cannot be deleted from an empty list"<< endl;
    return;
  }
  if(index == 0)
  {
      Node* t = head;
      head = head->next;
      delete t;
  }
  else
  {
      Node* temp = head->next;
      Node* pre = head;

      for(int i = 0 ; i < index-1; i++)
      {
          temp = temp->next;
          pre = pre->next;
      }
      Node* temp2 = temp;
      pre->next = temp->next;
      delete temp;
  }
}

void print(){
    //display the linklist
  Node* temp1 = head ;
  while(temp1 != NULL)
  {
      cout<< temp1->data << " " ;
      temp1 = temp1 -> next;
  }
  cout << endl;
}

void reversePrint(){

    Node* temp = head->next;
    Node* pre = head;

    while (temp != NULL){
        temp = temp->next;
    }

    while (temp!= head){
        pre = head;
        while(pre->next != temp){

            pre = pre->next;
        }
       temp = pre;
       cout << pre->data << " " ;
    }
}
