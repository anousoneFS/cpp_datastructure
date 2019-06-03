#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int value){
		data = value;
		next = NULL;
	}
	Node(){
		next = NULL;
	}
};

class Queue{
	public:
		Node *front;
		Node *rear;
		
	bool isempty(){
		if(front == NULL && rear == NULL){
			return true;
		}else{
			return false;
		}
	}
	void enqueue(int value){
		Node *newNode = new Node(value);
		if(isempty()){
			front = newNode;
			rear = newNode;
		}else{
			rear->next = newNode;
			rear = newNode;
		}
	}
	void dequeue(){
		if(isempty()){
			cout<<"!! Queue is empty"<<endl;
		}else{
			if(front == rear){
				delete(front);
				front = NULL;
				rear = NULL;
			}else{
				Node *cur=front;
				front = front->next;
				delete(cur);
			}
		}
	}
	void display(){
		Node *cur = new Node();
		cur = front;
		int i =1;
		if(isempty()){
			cout<<"!!! Queue is empty"<<endl;
		}
		while(cur != NULL){
			cout<<i<<".) "<<cur->data<<endl;
			cur = cur -> next;
			i++;
		}
	}
};
int main(){
Queue *myQueue = new Queue();
 char choice;
 int flag=1;
 int value;
 
 cout<<"\ni for enqueue; o for dequeue; f for showfront; d for displayQueue; q for exit;\n";
 while( flag == 1){
  cout<<"enter your choice:";
  cin>>choice;
  cout<<endl;
  switch (choice){
  case 'i': cout<<"Enter Value:";
          cin>>value;
          cout<<endl;
          myQueue->enqueue(value);
          break;
  case 'o': 
  		  myQueue->dequeue();
          break;
  case 'd': myQueue->display();
          break;
  case 'q': flag = 0;
          break;
  }
 }
cout<<"close program"<<endl;
 return 0;
}
