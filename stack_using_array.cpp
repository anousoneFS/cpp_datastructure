#include<iostream>
#include<string>
using namespace std;
#define SIZE 5
int A[SIZE];
int top=-1;

bool isempty(){
	if(top==-1)
		return true;
	else
		return false;
}

void push(int value){
	if(top==SIZE-1)
		cout<<"!!! stack is full, can not insert"<<endl;
	else{
		top++;
		A[top] = value;
		cout<<"==>>insert "<<A[top]<<" into "<<top+1<<endl;
		}
}
void pop(){
	if(isempty())
		cout<<"!!! stack is empty"<<endl;
	else{
		cout<<"delete "<<A[top]<<" at "<<top+1<<endl;
		top--;
	}
}
void display(){
	if(isempty())
		cout<<"!!! empty stack, can not display "<<endl;
	else{
		for(int i = 0; i<=top; i++){
			cout<<i+1<<".) "<<A[i]<<endl;
		}
	}
}
void showTop(){
	if(isempty())
		cout<<"!!! empty stack, can not display"<<endl;
	else
		cout<<"top = "<<A[top]<<"; at "<<top+1<<endl;
}
int main(){
	char x;
	int y;
	cout<<"SIZE stack = 5"<<endl;
	cout<<"press 'i' for insert into stack"<<endl;
	cout<<"press 'o' for delete "<<endl;
	cout<<"press 'd' for display all element of stack"<<endl;
	cout<<"press 't' for display top of stack"<<endl;
	cout<<"press 'q' for close program"<<endl;
	do{
		cout<<"------------->>> YOUR SHOICE IS :";
		cin>>x;
		switch(x){
			case 'i':
				cout<<"plese enter value = ";
				cin>>y;
				push(y);
				break;
			case 'd':
				display();
				break;
			case 'o':
				pop();
				break;
			case 't':
				showTop();
				break;	
		}
	}while(x != 'q');
	cout<<"close program"<<endl;
	return 0;
}
