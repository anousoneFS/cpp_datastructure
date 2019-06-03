#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	
	Node(){
		next = NULL;
	}
	
	Node(int value){
		data = value;
		next = NULL;
	}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;

		
	void addTotail(int value){
		Node *newNode = new Node(value);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		
	}
	
	void addTohead(int value){
		Node *newNode = new Node(value);
		
		if(head == NULL){
			addTotail(value);
		}else{
			newNode->next = head;
			head = newNode;
		}
		
	}
	void printAll(){
		Node *cur;
		
		cur = head;
		int n = 1;
		while(cur!=NULL){
			cout<<n<<".) "<<cur->data<<endl;
			cur = cur->next;
			n++;
		}
	}
};


int main(){
	LinkedList *myList = new LinkedList();
	myList->addTotail(22);
	myList->addTotail(44);
	myList->addTohead(11);
	myList->addTohead(32);
	myList->printAll();
	int n, x, y;
	do{
		cout<<"insert to head:";
		cin>>x;
		cout<<"insert to tail:";
		cin>>y;
		myList->addTohead(x);
		myList->addTotail(y);
		myList->printAll();
	}while(n!=3);
	
	
}
