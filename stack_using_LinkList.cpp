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

Node *top = NULL;
Node *head = NULL;

bool isempty(){
	if(top == NULL){
		return true;
	}else{
		return false;
	}
}
void push(int value){
	Node *newNode = new Node(value);
	if(isempty()){
		top = newNode;
		head = newNode;
	}else{
		top->next = newNode;
		top = newNode;
	}
}
int len(){
	Node *cur = new Node();
	cur = head;
	int i=1;
	while(cur != NULL){
		cur = cur->next;
		i++;
	}
	return i-1;	
}
void pop(){
	if(head != NULL){
		int l = len();
		Node *cur = new Node();
		cur = head;
		int n=1;
		
		while(cur != NULL){
			if(n == l-1){
				cur->next = NULL;
				top = cur;	
			}
			cur = cur->next;
			n++;
		}
		
	}else{
		cout<<"!! empty stack"<<endl;
	}
	
}
void display(){
	Node *cur = new Node();
	cur = head;
	int a=1;
	while(cur!=NULL){
		cout<<a<<".) "<<cur->data<<endl;
		cur = cur->next;
		a++;
	}
}

int main(){
	push(44);
	push(4);
	push(9);
	push(28);
	display();
	pop();
	pop();
	display();
	cout<<len()<<endl;
	return 0;
}
