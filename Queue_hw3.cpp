#include <iostream>
using namespace std;


struct Node{
char data;
Node *link;
};

Node *front = NULL;
Node *rear =  NULL;


bool isempty(){
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}


void enqueue ( char value ){
 Node *cur = new Node();
 cur->data= value;
 cur->link = NULL;

 if( front == NULL ){
  front = cur;
  rear = cur;
 }else{
  rear ->link = cur;
  rear = cur;
 }
}


void dequeue ( ){
 if( isempty() )
 cout<<"Queue is empty\n";
 
 else{
	 if( front == rear){
	  delete(front);
	  front = rear = NULL;
	 }
	 else{
	  Node *cur = front;
	  front = front->link;
	  delete(cur);
	 }
 }
}


void showfront( ){
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front is:"<<front->data<<endl;
}


void displayQueue(){
 if (isempty())
  cout<<"Queue is empty\n";
 else{
  Node *cur = front;
  
  while( cur != NULL){
   cout<<cur->data<<endl;
   cur= cur->link;
  }
 }
}


int main(){
 char choice;
 int flag=1;
 char value;
 
 cout<<"\ni for enqueue; o for dequeue; f for showfront; d for displayQueue; q for exit;\n";
 while( flag == 1){
  cout<<"enter your choice:";
  cin>>choice;
  cout<<endl;
  switch (choice){
  case 'i': cout<<"Enter Value:";
          cin>>value;
          cout<<endl;
          enqueue(value);
          break;
  case 'o': dequeue();
          break;
  case 'f': showfront();
          break;
  case 'd': displayQueue();
          break;
  case 'q': flag = 0;
          break;
  }
 }

 return 0;
}

