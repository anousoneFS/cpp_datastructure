#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *top = NULL;
bool isempty(){
	if(top == NULL){
		return true;
	}else{
		return false;
	}
}

void push(int value){
	Node *newNode = new Node();
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}
void pop(){
	if(isempty()){
		cout<<"!!! stack is empty"<<endl;
	}else{
		cout<<"you remove "<<top->data<<endl;
		Node *del = top;
		top = top->next;
		delete(del);
	}
	
}
void display(){
	int i=1;
	if(top == NULL){
		cout<<"can not display"<<endl;
	}
	Node *cur = top;
	while(cur != NULL){
		cout<<i<<".) "<<cur->data<<endl;
		cur = cur->next;
		i++;
	}
}
void showtop(){
	if(isempty()){
		cout<<"!stack is empty"<<endl;
	}else{
		cout<<"top is "<<top->data<<endl;
	}
}

int main(){
	char c ;
	int x;
	do{
		cout<<"enter your choice: ";
		cin>>c;
		switch(c){
			case 'i':
				cout<<"enter value: ";
				cin>>x;
				push(x);
				break;
			case 'o':
				pop();
				break;
			case 'f':
				showtop();
				break;
			case 'd':
				display();
				break;
		}
	}while(c != 'q');
	
	return 0;
}

