#include<iostream>
using namespace std;

#define SIZE 5
int front=-1, rear=-1;
int A[SIZE];

bool isempty(){
	if(front==-1 && rear==-1)
		return true;
	else
		return false;
}
void enqueue(int value){
	if(rear == SIZE-1)
		cout<<"!!! Queue is full"<<endl;
	else{
		if(isempty())
			front=0;
		rear++;
		A[rear] = value;
		cout<<"---> insert "<<A[rear]<<" into rear:"<<rear+1<<endl;
	}	
}
void dequeue(){
	if(isempty())
		cout<<"!!! Queue is empty"<<endl;
	else{
		cout<<"---> delete "<<A[front]<<" at front:"<<front+1<<endl;
		if(front == rear)
			front = rear = -1;
		else
			front++;
	}
}
void showfront(){
	if(isempty())
		cout<<"!!! Queue is empty"<<endl;
	else
		cout<<"front="<<A[front]<<" at "<<front+1<<endl;
}
void display(){
	if(isempty())
		cout<<"!!! can not display queue"<<endl;
	else{
		int n=1;
		for(int i=front; i<=rear; i++){
			cout<<n<<".) "<<A[i]<<endl;
			n++;
		}
	}
}

int main(){
	cout<<"press 'i' for insert to queue"<<endl;
	cout<<"press 'o' for delete from queue"<<endl;
	cout<<"press 'd' for displayQueue"<<endl;
	cout<<"press 'f' for showfront"<<endl;
	cout<<"press 'q' for exit "<<endl;
	char c;
	int x;
	do{
		cout<<"enter your choice:";
		cin>>c;
		
		if(c == 'i'){
			cout<<"enter value:";
			cin>>x;
			enqueue(x);
		}else if(c == 'o'){
			dequeue();
		}else if(c == 'd'){
			display();
		}else if(c == 'f'){
			showfront();
		}else if(c == 'q'){
			cout<<"close program!!!"<<endl;	
		}else{
			cout<<"ERROR"<<endl;
		}
		
	}while(c != 'q');
	
	return 0;
}
